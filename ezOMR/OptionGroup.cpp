//
//  OptionGroup.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "OptionGroup.h"

OptionGroup::OptionGroup(){
    key = "";
}

OptionGroup::OptionGroup(string k) {
    key.assign(k);
}

OptionGroup:: ~OptionGroup(){
    
}

string OptionGroup::optionKey(){
    return key;
}

vector<Option> OptionGroup::options() {
    return opts;
}

void OptionGroup::addOption(Option opt) {
    opts.push_back(opt);
}

void OptionGroup::resetI(){
    i=0;
}

Option OptionGroup::nextOption(){
    if(i< opts.size())
        return opts[i++];
    return NULL;
}
