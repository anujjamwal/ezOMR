//
//  Page.cpp
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "Page.h"

Page :: Page(float w, float h) {
    width = w;
    height = h;
}

float Page::getHeight(){
    return height;
}

float Page::getWidth(){
    return width;
}