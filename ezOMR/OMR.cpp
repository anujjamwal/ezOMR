//
//  OMR.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "OMR.h"
#include "ImageUtils.h"
#include "OMRSheetUtils.h"
#include <fstream>
#include <string>
#include <opencv.hpp>
#include <cvblobs/Blob.h>
#include <cvblobs/BlobResult.h>
#include <cvblobs/BlobOperators.h>


using namespace std;

OMR :: OMR(string file):fileLoc(file), initialized(0){}

int OMR::init(){
    loadOptions(fileLoc, &optiongroups);
    loadOptionsMap();
    initialized = 1;
    return 0;
}

int OMR::reset(){
    delete optionMap;
    optiongroups.clear();
    initialized = 0;
    return 0;
}

vector<OmrChoice> OMR::process(OMRSheet * sheet){
    if(!initialized){
        throw "Cannot process before init";
    }
    
    vector<OmrChoice> choices;
    Image * image = sheet->originalImage();

    sheet -> locateCornerMarkers(50, 50);
    
    char *ch = new char[2];
    ch[1] = '\0';
    
    vector<Bubble> bubbles = sheet->getBubbles();
    for (int i = 0; i < bubbles.size(); i++ ){
        Point * center = bubbles[i].center();
        Point * centroid = bubbles[i].actualCenter();
        Option * option = & optionMap[center->y()][center->x()];
        if(option -> isValid()) {
            cvCircle(image->getImage(), cvPoint(centroid->x(), centroid->y()), 15, CV_RGB(255, 0, 0));
//            std::cout<< "Found a filled bubble "<<option->answer()<<" at "<<center ->x()<<std::endl;
            ch[0] = groups[center->y()][center->x()];
            choices.push_back(OmrChoice(optiongroups.at(ch).optionKey(), option ->answer()));
            
        }

    }
    delete ch;
    
    return choices;
}

OMR::~OMR(){
    delete optionMap;
    delete groups;
}

void OMR::loadOptionsMap(){
    
    string line, file;
    row = col =0;
    file.append(fileLoc).append("page.omr");
    
    ifstream myfile(file.data());
    if (myfile.is_open())
    {
        getline (myfile,line);
        row++;
        col = (int)line.length();
        while ( myfile.good() )
        {
            getline(myfile, line);
            row++;
        }
        //initialize the option map
        
        optionMap = new Option *[row];
        groups = new char* [row];
        
        for(int i=0;i< row; i++){
            optionMap[i] = new Option[col];
            groups[i] = new char[col];
        }
        myfile.close();
    }
    
    myfile.open(file.data());
    if (myfile.is_open())
    {
        row = 0;
        char ch[2];
        ch[1] = '\0';
        
        while ( myfile.good() )
        {
            getline (myfile,line);
            for(col = 0; col < line.length(); col++){
                groups[row][col] = line[col];
                if((ch[0] = line[col]) == '-'){
                    //                    optionMap[row][col].to_s();
                    continue;
                } else {
                    //                    cout<<"row: "<<row<<" col: "<<col<<endl;
                    optionMap[row][col] = optiongroups.at(string(ch)).nextOption();
                    //                    optionMap[row][col].to_s();
                }
            }
            row++;
        }
        
        myfile.close();
    }

}

