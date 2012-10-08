//
//  OmrChoice.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "OmrChoice.h"
OmrChoice::OmrChoice(string k, string a){
    key.assign(k);
    ans.assign(a);
}

OmrChoice::~OmrChoice(){
}

std::string OmrChoice::question() {
    return key;
}

std::string OmrChoice::answer(){
    return ans;
}