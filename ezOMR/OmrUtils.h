//
//  OmrUtils.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__OmrUtils__
#define __omr__OmrUtils__

#include <iostream>
#include "Option.h"
#include "OptionGroup.h"
#include <string>
#include <map>

using namespace std;

void loadOptions(string fileLoc, map<string, OptionGroup> * optiongroups);
Option ** loadOptionsMap(string fileLoc, map<string, OptionGroup> * optiongroups);
#endif /* defined(__omr__OmrUtils__) */
