//
//  PrecondViolatedExcep.hpp
//  CS 110C Assignment 5: High Scores
//
//  Created by vasyl golub on 3/17/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef PrecondViolatedExcep_hpp
#define PrecondViolatedExcep_hpp

#include <stdio.h>

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
    PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep

#endif /* PrecondViolatedExcep_hpp */
