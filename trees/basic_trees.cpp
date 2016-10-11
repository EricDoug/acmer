//
//  basic_trees.cpp
//  acmer
//
//  Created by EricDoug on 16/9/13.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "basic_trees.h"

void create(BTreeNode *&root){
    int m;
    cin >> m;
    if(m == -1){
        root = NULL;
        return;
    }
    root = new BTreeNode(m);
    create(root->left);
    create(root->right);
    return;
}

int depth(BTreeNode *root){
    if (root == NULL) {
        return 0;
    }
    int left_depth = 0,right_depth = 0;
    left_depth = depth(root->left);
    right_depth = depth(root->right);
    
    return left_depth > right_depth ? (left_depth+1):(right_depth+1);
}

bool isBalance(BTreeNode *root){
    if (root == NULL) {
        return true;
    }
    
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    int diff = abs(left_depth - right_depth);
    if(diff > 1)
        return false;
    
    return isBalance(root->left) && isBalance(root->right);
}
