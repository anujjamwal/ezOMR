//
//  OMRSheetUtils.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "OMRSheetUtils.h"
#include "ImageUtils.h"


Point* OMRSheetUtils::findRectanglemarkers(Image * image, int sizeX, int sizeY) {
    Point * markers = new Point[4];
    int height = image->height();
    int width  = image->width();
    
    markers[0] = ImageUtils::findCentroid(image, 5, 5, sizeX, sizeY);
    markers[1] = ImageUtils::findCentroid(image, width-sizeX, 5, width-5, sizeY);
    markers[2] = ImageUtils::findCentroid(image, width-sizeX, height-sizeY, width-5, height-5);
    markers[3] = ImageUtils::findCentroid(image, 5, height-sizeY, sizeX, height-5);
    
    return markers;
}