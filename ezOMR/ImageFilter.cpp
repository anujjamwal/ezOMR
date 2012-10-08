//
//  ImageFilter.cpp
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "ImageFilter.h"
#include <opencv2/opencv.hpp>

Image * ImageFilter::threshold(Image * image, double threshold, double maxVal) {
    Image * clonedImage = image->clone();
    cvThreshold(image->getImage(), clonedImage->getImage(), threshold, maxVal, CV_THRESH_BINARY);
    return clonedImage;
}

Image * ImageFilter::grayscale(Image *image) {
    Image * clonedImage = new Image(image->getImage()->width, image->getImage()->height, GRAYSCALE);
    cvCvtColor( image->getImage(), clonedImage->getImage(), CV_RGB2GRAY );
    return clonedImage;
}