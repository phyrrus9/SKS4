//
//  filesystem.h
//  SKS4
//
//  Created by Ethan Laur on 8/28/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#ifndef SKS4_filesystem_h
#define SKS4_filesystem_h
#include "./environment.h"
#include <fstream>
void save(_environment_data &);
void restore(_environment_data &);
#endif
