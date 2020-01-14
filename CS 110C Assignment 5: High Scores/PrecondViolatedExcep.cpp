//
//  PrecondViolatedExcep.cpp
//  CS 110C Assignment 5: High Scores
//
//  Created by vasyl golub on 3/17/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include "PrecondViolatedExcep.hpp"
PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.
