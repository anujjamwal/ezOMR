//
//  ImageFilter.h
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__ImageFilter__
#define __omr__ImageFilter__

#include <iostream>
#include "Image.h"

class ImageFilter {
    public:
    static Image * threshold(Image * image, double threshold, double maxVal);
    static Image * grayscale(Image * image);
};
#endif /* defined(__omr__ImageFilter__) */
