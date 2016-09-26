//
//  xiaomi.h
//  acmer
//
//  Created by EricDoug on 16/9/26.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#ifndef acmer_xiaomi_h
#define acmer_xiaomi_h

#include "pre_func.h"
#include <stack>

struct TNode{
    int value;
    struct TNode* left;
    struct TNode* right;
    TNode(int x) : value(x), left(NULL), right(NULL){}
};

int xiaomi_1();
int xiaomi_3();
int xiaomi_4();

#endif
