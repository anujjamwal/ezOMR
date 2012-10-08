//
//  Image.h
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__Image__
#define __omr__Image__

#include <iostream>
#include <opencv2/opencv.hpp>


const int GRAYSCALE = 1;
const int RGB = 2;

class Image {
    public:
    Image(IplImage * img);
    
    // reads the image from the file
    Image(const char* filename);
    Image(int width, int height, int type);
    
    IplImage * getImage();
    Image * clone();
    int height();
    int width();
    
    ~Image();
    
    private:
    IplImage *image;
};
#endif /* defined(__omr__Image__) */
