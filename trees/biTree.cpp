//
//  biTree.cpp
//  acmer
//
//  Created by EricDoug on 16/9/15.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "biTree.h"

BinTree* Binary_Tree::find(int value) {
    
    if(root == NULL)
        return NULL;
    
    BinTree* pNode = root;
    while (pNode) {
        if (value < pNode->val) {
            pNode = pNode->left;
        }
        else if(value > pNode->val) {
            pNode = pNode->right;
        }
        return pNode;
    }
    
    return NULL;
}

/***********************************
 *           递归插入节点            *
 ***********************************/
bool Binary_Tree::_insert(BinTree*& root, int value) {
    if(!root){
        root = new BinTree(value);
        return true;
    }
    
    if (value < root->val) {
        return _insert(root->left, value);
    }
    if (value > root->val) {
        return _insert(root->left, value);
    }
    
    return false;
}

/***********************************
 *         非递归插入节点            *
 ***********************************/
bool Binary_Tree::_insert2(int value) {
    // 没有节点
    if (!root) {
        root = new BinTree(value);
        return true;
    }
    
    // 找到需要插入的位置
    BinTree* pNode = root;
    BinTree* pCur = root;
    while (pNode) {
        pCur = pNode;
        if(value < pNode->val)
            pNode = pNode->left;
        else if(value > pNode->val)
            pNode = pNode->right;
        else
            return false; // 插入的值已经存在
    }
    if (value < pCur->val) {
        pCur->left = new BinTree(value);
    }
    else if(value > pCur->val) {
        pCur->right = new BinTree(value);
    }
    
    return true;
}

/********************************
 *          删除叶节点            *
 ********************************/
void Binary_Tree::deleteChildless(BinTree *pParent, BinTree *pNode){
    //若删除节点是根节点
    if (pNode == root) {
        root = NULL;
    }
    // 若删除节点是父亲节点的左孩子
    else if(pParent->left == pNode) {
        pParent->left = NULL;
    }
    // 若删除节点是父亲节点的右孩子
    else if(pParent->right == pNode) {
        pParent->right = NULL;
    }
    delete pNode;
}

/**********************************
 *      删除只有一个孩子的节点        *
 **********************************/
void Binary_Tree::deleteSingleSon(BinTree *pParent,BinTree *pNode){
    // 找到孙子节点
    BinTree* grandSon = pNode->left ? pNode->left:pNode->right;
    if (pNode == root) {
        pParent = grandSon;
    }
    else if(pParent->left == pNode) {
        pParent->left = grandSon;
    }
    else if(pParent->right == pNode){
        pParent->right = grandSon;
    }
    
    delete pNode;
}

