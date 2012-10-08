//
//  ImageUtils.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__ImageUtils__
#define __omr__ImageUtils__

#include <iostream>
#include "Point.h"
#include "Image.h"
#include <cvblobs/BlobResult.h>

class ImageUtils {
    public:
    static Point findCentroid(Image * image, int x1, int y1, int x2, int y2, int color = 50);
    static Point findCentroid(Image * image, CvRect * rect, int color = 50);
    static CBlobResult findBlobs(Image * image, int minArea, int maxArea, CvRect rect = cvRect(0, 0, 0, 0)) ;
};
#endif /* defined(__omr__ImageUtils__) */
