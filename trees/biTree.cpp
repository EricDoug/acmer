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

/*********************************
 *            删除节点            *
 *********************************/
bool Binary_Tree::deleteNode(int value){
    if(!root)
        return false;
    // 查找到待删除的节点
    BinTree* pNode = root;
    BinTree* pParent = NULL;
    while (pNode) {
        if (value < pNode->val) {
            pParent = pNode;
            pNode = pNode->left;
        }
        else if(value > pNode->val){
            pParent = pNode;
            pNode = pNode->right;
        }
        else{
            break;  // 找到待删除的节点
        }
    }
    if(!pNode)
        return false;
    
    if (!pNode->left && !pNode->right) {  // 若待删除节点是叶节点
        deleteChildless(pParent, pNode);
    }
    else if(!pNode->left || !pNode->right){  // 待删除节点只有一个孩子节点
        deleteSingleSon(pParent, pNode);
    }
    else {
        BinTree* pCur = pNode;  // 暂存待删除节点
        pParent = pNode;
        // 找到直接前驱节点,即左孩子的最右节点
        pNode = pNode->left;
        while (pNode->right) {
            pParent = pNode;
            pNode = pNode->right;
        }
        pCur->val = pNode->val;
        if(!pNode->left)
            deleteChildless(pParent, pNode);
        else
            deleteSingleSon(pParent, pNode);
    }
    
    return true;
    
}

/*******************************
 *           前序遍历           *
 *******************************/
void Binary_Tree::preOrder(BinTree* root){
    if(root){
        cout << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

/***********************************
 *          非递归前序遍历           *
 ***********************************/
void Binary_Tree::preOrder1(BinTree *root){
    if(!root)
        return;
    
    stack<BinTree*> s;
    s.push(root);
    BinTree* pCur;
    while(!s.empty()) {
        pCur = s.top();
        s.pop();
        cout << pCur->val << endl;
        if (pCur->right) {
            s.push(pCur->right);
        }
        if(pCur->left) {
            s.push(pCur->left);
        }
    }
}

void Binary_Tree::visit(BinTree *pNode){
    if (pNode) {
        cout << pNode->val << endl;
    }
}

/***************************************
 *              中序遍历                *
 ***************************************/
void Binary_Tree::inOrder(BinTree *root){
    if(root) {
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}


/**************************************
 *            非递归中序遍历            *
 **************************************/
void Binary_Tree::inOrder1(BinTree *root) {
    
    stack<BinTree*> s;
    BinTree *pCur = root;
    while (pCur || !s.empty()) {
        // 找最左孩子
        while (pCur) {
            s.push(pCur);
            pCur = pCur->left;
        }
        if (!s.empty()) {
            pCur = s.top();  // 先访问最左孩子
            s.pop();
            visit(pCur);
            pCur = pCur->right;
        }
    }
    
}

/*****************************************
 *             非递归中序遍历2              *
 ******************************************/
void Binary_Tree::inOrder2(BinTree *root) {
    if (!root) {
        return;
    }
    
    stack<pair<BinTree*, int>> s;
    s.push(make_pair(root, 0));
    int times;
    BinTree* pCur;
    while (!s.empty()) {
        pCur = s.top().first;
        times = s.top().second;
        s.pop();
        if (times == 0) {   // 第一次压栈
            if(pCur->right)
                s.push(make_pair(pCur->right, 0));
            s.push(make_pair(pCur, 1)); // 第二次压栈
            if (pCur->left) {
                s.push(make_pair(pCur->left, 0));
            }
        }
        else {
            visit(pCur);
        }
    }

}
 
