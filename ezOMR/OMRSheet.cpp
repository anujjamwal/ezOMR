//
//  OMRSheet.cpp
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "OMRSheet.h"
#include "OMRSheetUtils.h"
#include "ImageUtils.h"
#include <cvblobs/Blob.h>
#include <cvblobs/BlobResult.h>
#include <cvblobs/BlobOperators.h>
#include "ImageFilter.h"

OMRSheet::OMRSheet(Image * image, int markArea) {
    intialImage = image;
    
    //thresholding
    rawSheet = ImageFilter::threshold(ImageFilter::grayscale(image), 100, 255);
    
    bubbleArea = markArea;
    x1=y1=x2=y2=0;
}

Image * OMRSheet::image(){
    return rawSheet;
}

void OMRSheet::locateCornerMarkers(int regionWidth, int regionHeight){
    markers = OMRSheetUtils::findRectanglemarkers(rawSheet, regionWidth, regionHeight);
    x1 = markers[0].x();
    y1 = markers[0].y();
    x2 = markers[2].x();
    y2 = markers[2].y();

}

Image * OMRSheet::originalImage(){
    return intialImage;
}

vector<Bubble> OMRSheet::getBubbles(int xi1, int yi1, int xi2, int yi2){
    vector <Bubble> bubbles;
    cout<<"Bubble area "<<bubbleArea;
    int minArea = bubbleArea/2, maxArea = bubbleArea*1.5;
    CBlobResult blobs = ImageUtils::findBlobs(rawSheet, minArea, maxArea, cvRect(xi1, yi1, xi2-xi1, yi2-yi1));
    for (int i = 0; i < blobs.GetNumBlobs(); i++ )
    {
        CvRect rect = blobs.GetBlob(i)->GetBoundingBox();
        Point centroid = ImageUtils::findCentroid(rawSheet, &rect);
        Point centroidMM((centroid.x() - x1)/15, (centroid.y() - y1)/15);
        Bubble bubble(blobs.GetBlob(i), &centroidMM, &centroid);
        bubbles.push_back(bubble);
        
    }
    
    return bubbles;
}