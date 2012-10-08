//
//  main.cpp
//  libOMR
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include <iostream>
#include <opencv.hpp>
#include "Image.h"
#include "ImageFilter.h"
#include "OMRSheetUtils.h"
#include "ImageUtils.h"
#include "OMR.h"

#include <cvblobs/Blob.h>
#include <cvblobs/BlobResult.h>
#include <cvblobs/BlobOperators.h>

int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Image * image2;
    
    try {
        image2 = new Image("/Users/anuj/Workspace/ezOMR/test/sheet-filled.png");
        
    } catch(char * exception) {
        std::cout << exception;
        return 1;
    }
    
    
    OMRSheet * omrSheet = new OMRSheet(image2);
    
    OMR omr("/Users/anuj/Workspace/ezOMR/test/");
    cout << "created  the OMR" << endl;
    omr.init();
    cout << "initialized the OMR" << endl;
    vector<OmrChoice> choices = omr.process(omrSheet);
    
    // display the result
    cout<< endl;
    cout << left;
    cout<<setw(10)<<"S.No."<<setw(20)<<"Key"<<setw(20)<<"Answer"<<endl;
    for(int i=0; i<choices.size();i++){
        cout<<setw(10)<<i<<setw(20)<<choices[i].question()<<setw(20)<<choices[i].answer()<<endl;
    }
    
    // Display the image.
    cvNamedWindow("Image:", CV_WINDOW_AUTOSIZE);
    cvShowImage("Image:", image2->getImage());
    
    // Wait for the user to press a key in the GUI window.
    cvWaitKey(0);
    
    // Free the resources.
    cvDestroyWindow("Image:");
    
    return 0;
}



