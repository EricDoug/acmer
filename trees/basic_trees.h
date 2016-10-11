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

struct BTreeNode{
    int value;
    struct BTreeNode* left;
    struct BTreeNode* right;
    BTreeNode(int x) : value(x), left(NULL), right(NULL){}
};

// 建立二叉树
void create(BTreeNode *&root);

// 求二叉树高度
int depth(BTreeNode *root);

// 判断是否为平衡二叉树
bool isBalance(BTreeNode *root);

#endif /* defined(__acmer__basic_trees__) */
