//
//  basic_trees.h
//  acmer
//
//  Created by EricDoug on 16/9/13.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#ifndef __acmer__basic_trees__
#define __acmer__basic_trees__

#include "pre_func.h"

struct TNode{
    int value;
    struct TNode* left;
    struct TNode* right;
    TNode(int x) : value(x), left(NULL), right(NULL){}
};

#endif /* defined(__acmer__basic_trees__) */
