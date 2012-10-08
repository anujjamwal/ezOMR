//
//  ImageUtils.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "ImageUtils.h"
#include <cvblobs/Blob.h>
#include <cvblobs/BlobResult.h>
#include <cvblobs/BlobOperators.h>

Point ImageUtils::findCentroid(Image * image, int x1, int y1, int x2, int y2, int color){
//    std::cout<<"x axis: "<<x1<<" - "<<x2<<std::endl;
//    std::cout<<"y axis : "<<y1<<" - "<<y2<<std::endl;
//    std::cout<<"color : "<<color<<std::endl;
    
    IplImage * frame = image->getImage();
    
    int tx = 0, ty = 0, count = 0;
    
    for( int y=y1; y < y2; y++ ) {
        uchar* ptr = (uchar*) ( frame->imageData + y * frame->widthStep );
        for( int x=x1; x < x2; x++ ) {
            if(ptr[x] <= color) {
                tx += x;
                ty += y;
                count ++;
//                std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
            }
            //std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
        }
    }
//    std::cout<<"x: "<<tx/count<<" y: "<<ty/count<<std::endl;
//    std::cout<<"count : "<<count<<std::endl;
    
    
    if(count == 0){
        
        return Point(0,0);
    }
    return Point(tx/count, ty/count);
    
}

Point ImageUtils::findCentroid(Image * image, CvRect * rect, int color) {
    return findCentroid(image, rect->x, rect->y, rect->x + rect->width - 1, rect->y + rect->height - 1);
}

CBlobResult ImageUtils::findBlobs(Image * image, int minArea, int maxArea, CvRect boundRect) {
    CBlobResult blobs;
    CBlob biggestBlob;;
    
    
    // find non-white blobs in thresholded image
    blobs = CBlobResult( image->getImage(), NULL, 255 );
    // exclude the ones smaller than param2 value
    blobs.Filter( blobs, B_EXCLUDE, CBlobGetArea(), B_LESS, minArea );
    blobs.Filter( blobs, B_EXCLUDE, CBlobGetArea(), B_GREATER, maxArea );
    
    //bounding rectangle
    if(boundRect.width > 0) {
        blobs.Filter( blobs, B_INCLUDE, CBlobGetMinX(), B_GREATER, boundRect.x );
        blobs.Filter( blobs, B_INCLUDE, CBlobGetMinY(), B_GREATER, boundRect.y );
        blobs.Filter( blobs, B_EXCLUDE, CBlobGetMaxX(), B_GREATER, boundRect.x + boundRect.width );
        blobs.Filter( blobs, B_EXCLUDE, CBlobGetMaxY(), B_GREATER, boundRect.y + boundRect.height );
    }
    
    // get mean gray color of biggest blob
    CBlobGetMean getMeanColor( image->getImage() );
    double meanGray;
    
    blobs.GetNthBlob( CBlobGetArea(), 0, biggestBlob );
    meanGray = getMeanColor( biggestBlob );
    
//    std::cout << "blobs found "<<blobs.GetNumBlobs();
    return blobs;

}