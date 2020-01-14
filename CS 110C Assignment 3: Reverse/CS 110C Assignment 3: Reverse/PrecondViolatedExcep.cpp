//
//  PrecondViolatedExcep.cpp
//  CS 110C Assignment 3: Reverse
//
//  Created by vasyl golub on 2/24/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include "PrecondViolatedExcep.hpp"
#include <iostream>
using namespace std;

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
   
}  // end constructor

// End of implementation file.

