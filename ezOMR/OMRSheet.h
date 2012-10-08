//
//  OMRSheet.h
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__OMRSheet__
#define __omr__OMRSheet__

#include <iostream>
#include "Image.h"
#include "Page.h"
#include "Bubble.h"
#include "Point.h"
#include <vector>

using namespace std;

class OMRSheet {
    public:
    OMRSheet(Image *image, int markArea = 150);
    Image * image();
    Image * originalImage();
    void locateCornerMarkers(int regionWidth, int regionHeight);
    vector<Bubble> getBubbles(int x1=0, int y1=0, int x2=0, int y2=0);
    
    private:
    
//    Page * basePage;
    float scaleRatio;
    Image * rawSheet;
    Image * intialImage;
    Point * markers;
    int bubbleArea;
    int x1, y1, x2, y2;
};

#endif /* defined(__omr__OMRSheet__) */
