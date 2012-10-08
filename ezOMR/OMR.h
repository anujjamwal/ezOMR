//
//  OMR.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__OMR__
#define __omr__OMR__

#include <iostream>
#include <vector>
#include <map>
#include "Option.h"
#include "OptionGroup.h"
#include "OmrChoice.h"
#include "OMRSheet.h"
#include "Point.h"
#include "OmrUtils.h"

class OMR {
    public:
    OMR(string file);
    int init(); //load the congfig from the file
    int reset(); // reset the loaded configurations
    std::vector<OmrChoice> process(OMRSheet * image);
    ~OMR();
    
    private:
    Option ** optionMap;
    char ** groups;
    int row, col;
    
    std::map<string, OptionGroup> optiongroups;
    string fileLoc;
    int initialized;

    //move to ORMsheet
    Point * markers;
    void loadOptionsMap();

    
};
#endif /* defined(__omr__OMR__) */
