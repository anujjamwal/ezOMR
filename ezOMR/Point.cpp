//
//  Point.cpp
//  omr
//
//  Created by Anuj Jamwal on 06/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "Point.h"
#include <math.h>

Point::Point(int i, int j) {
    px = i;
    py = j;
}


Point::Point(){
    px=0;
    py=0;
}

Point::Point(Point * point){
    px = point -> px;
    py = point->py;
}

int Point::distance(Point *p) {
    return sqrt(pow(px - p->x(), 2) + pow(py - p->y(), 2));
}

double Point::slope(Point *p) {
    return (p->y() - py)/(p->x() - px);
}

int Point::x(){
    return px;
}

int Point::y(){
    return py;
}