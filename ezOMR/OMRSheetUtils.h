//
//  OMRSheetUtils.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__OMRSheetUtils__
#define __omr__OMRSheetUtils__

#include <iostream>
#include "OMRSheet.h"
#include "Point.h"

class OMRSheetUtils {
    public:
    static Point* findRectanglemarkers(Image * image, int sizeX, int sizeY);
};
#endif /* defined(__omr__OMRSheetUtils__) */
