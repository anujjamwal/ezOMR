//
//  OmrUtils.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "OmrUtils.h"
#include <fstream>
#include <boost/algorithm/string.hpp>


using namespace std;


void loadOptions(string fileLoc, map<string, OptionGroup> * optiongroups){
    string line;
    string file;
    file.append(fileLoc).append("page.data");
    
    ifstream myfile(file.data());
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            vector<std::string> strs;
            boost::split(strs, line, boost::is_any_of(" "));
            
            OptionGroup group(strs[2]);
            
            for(int i=3; i< strs.size(); i++) {
                Option option(strs[i]);
                //                option.group(&group);
                group.addOption(option);
            }
            optiongroups->operator[](strs[0]) = group;
            
        }
        myfile.close();
    }
    
    //    std::cout<<"Option group map size: "<<optiongroups->size()<<endl;
}

Option** loadOptionsMap(string fileLoc, map<string, OptionGroup> * optiongroups){
    
    string line, file;
    Option ** optionMap;
    int row = 0, col = 0;
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
        for(int i=0;i< row; i++){
            optionMap[i] = new Option[col];
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
                if((ch[0] = line[col]) == '-'){
//                    optionMap[row][col].to_s();
                    continue;
                } else {
                    //                    cout<<"row: "<<row<<" col: "<<col<<endl;
                    optionMap[row][col] = optiongroups->at(string(ch)).nextOption();
//                    optionMap[row][col].to_s();
                }
            }
            row++;
        }
        
        myfile.close();
    }
    return optionMap;
}
