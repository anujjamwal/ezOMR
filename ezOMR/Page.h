//
//  Page.h
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__Page__
#define __omr__Page__

#include <iostream>
class Page {
    
    public:
    
    Page(float width, float height);
    float getHeight();
    float getWidth();
    
    
    private:
    float width;
    float height;
    
};

#endif /* defined(__omr__Page__) */
