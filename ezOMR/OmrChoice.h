//
//  OmrChoice.h
//  omr
//
//  Created by Anuj Jamwal on 07/10/12.
//  Copyright (c) 2012 Anuj Jamwal. All rights reserved.
//

#ifndef __omr__OmrChoice__
#define __omr__OmrChoice__

#include <iostream>
#include <string>

using namespace std;

class OmrChoice {
    public:
    OmrChoice(string key, string ans);
    ~OmrChoice();
    std::string question();
    std::string answer();
    
    private:
    std::string key;
    std::string ans;
};
#endif /* defined(__omr__OmrChoice__) */
