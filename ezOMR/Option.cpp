//
//  Option.cpp
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#include "Option.h"

Option::Option(){
    valid = 1;
    ans.assign("");
};

Option::Option(string a){
    ans.assign(a);
    valid = 0;
}

Option::Option(Option * o){
    ans.assign(o->ans);
    valid = 0;
}

Option::~Option(){
//    grp = NULL;
}

string Option::answer(){
    return ans;
}

int Option::isValid(){
    return valid == 0;
}

void Option::to_s(){
    cout<<"valid: "<<valid;
    cout<<" answer: "<<ans;
}

//OptionGroup * Option::group(){
//    return grp;
//}

//void Option::group(OptionGroup * group){
//    grp = group;
//}