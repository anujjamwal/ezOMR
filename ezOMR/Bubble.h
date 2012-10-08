//
//  Bubble.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__Bubble__
#define __omr__Bubble__

#include <iostream>
#include "Point.h"
#include <cvblobs/Blob.h>

class Bubble {
    
    public:
    Bubble();
    Bubble(CBlob *blob, Point * centroid, Point * actualPoint);
    Point * center();
    Point * actualCenter();
    int area();
    
    private:
    Point * cen;
    Point * actCenter;
    CBlob * blob;
};
#endif /* defined(__omr__Bubble__) */
