//
//  Option.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__Option__
#define __omr__Option__

#include <iostream>
#include <string>

using namespace std;

class Option {
    public:
    Option();
    Option(Option * o);
    Option(string answer);
    string answer();
    int isValid();
//    OptionGroup * group();
//    void group(OptionGroup * group);
    ~Option();
    
    void to_s();
    
    private:
    string ans;
    int valid;
//    OptionGroup * grp;
    
};
#endif /* defined(__omr__Option__) */
