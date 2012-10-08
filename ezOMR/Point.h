//
//  Point.h
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__Point__
#define __omr__Point__

#include <iostream>
class Point {
    public:
    Point();
    Point(int i, int j);
    Point(Point * p);
    int distance(Point *p);
    double slope(Point *p);
    int x();
    int y();
    
    private:
    int px, py;
};
#endif /* defined(__omr__Point__) */
