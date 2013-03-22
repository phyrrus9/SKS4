//
//  intelligence.h
//  SKS4
//
//  Created by Ethan Laur on 8/29/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#ifndef __SKS4__intelligence__
#define __SKS4__intelligence__
#include "engine.h"
#include "Thread.h"

extern _environment_data env;

class intelligence : public tpool::Thread
{
    void Entry();
    void smartbuttons(void);
public:
    void go(void);
    void stop(void);
};

#endif /* defined(__SKS4__intelligence__) */
