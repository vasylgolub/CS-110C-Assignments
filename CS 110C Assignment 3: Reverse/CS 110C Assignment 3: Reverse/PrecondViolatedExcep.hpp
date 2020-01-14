//
//  PrecondViolatedExcep.hpp
//  CS 110C Assignment 3: Reverse
//
//  Created by vasyl golub on 2/24/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
    PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep
#endif
