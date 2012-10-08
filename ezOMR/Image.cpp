//
//  Image.cpp
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "Image.h"

Image::Image(IplImage *img) {
    image = cvCloneImage(img);
}

Image::Image(const char* filename) {
    image = cvLoadImage(filename);
    if(!image) {
        throw "Image Not Found";
    }
}

Image::Image(int width, int heigth, int type) {
    switch(type){
        case GRAYSCALE: image = cvCreateImage(cvSize(width, heigth), IPL_DEPTH_8U, 1); return;
    }
    
    image = cvCreateImage(cvSize(width, heigth), IPL_DEPTH_8U, 3);
}

IplImage * Image :: getImage() {
    return image;
}

Image:: ~Image() {
    cvReleaseImage(&image);
}

Image * Image::clone() {
    return new Image(image);
}

int Image::height(){
    return image -> height;
}

int Image::width(){
    return image -> width;
}