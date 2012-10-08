//
//  OptionGroup.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__OptionGroup__
#define __omr__OptionGroup__

#include <iostream>
#include <string>
#include <vector>
#include "Option.h"

using namespace std;

class OptionGroup {
    public:
    OptionGroup();
    OptionGroup(string  key);
    string optionKey();
    void addOption(Option opt);
    vector<Option> options();
    Option nextOption();
    void resetI();
    ~OptionGroup();
    
    private:
    string key;
    vector<Option> opts;
    int i = 0;
};
#endif /* defined(__omr__OptionGroup__) */
