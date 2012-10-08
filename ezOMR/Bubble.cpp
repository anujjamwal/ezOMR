//
//  Bubble.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "Bubble.h"

Bubble::Bubble(CBlob * b, Point * centroid, Point * actualPoint) {
    cen = new Point(centroid);
    blob = b;
    actCenter = new Point(actualPoint);
}

Point * Bubble::center(){
    return cen;
}

int Bubble::area(){
    return blob -> Area();
}

Point * Bubble::actualCenter(){
    return actCenter;
}