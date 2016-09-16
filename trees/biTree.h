//
//  biTree.h
//  acmer
//
//  Created by EricDoug on 16/9/15.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#ifndef __acmer__biTree__
#define __acmer__biTree__

#include "pre_func.h"
#include<stack>

struct BinTree {
    int val;
    struct BinTree* left;
    struct BinTree* right;
    BinTree(int x) : val(x), left(NULL), right(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL), right(NULL) {}
};

class Binary_Tree {
private:
    BinTree* root;
    bool _insert(BinTree*& root,int value);  // 递归
    bool _insert2(int value);  // 非递归
    void deleteChildless(BinTree* pParent,BinTree* pNode); // 删除叶节点
    void deleteSingleSon(BinTree* pParent,BinTree* pNode); // 删除只有一个孩子节点
    
public:
    Binary_Tree();
    ~Binary_Tree();
    
    bool insert(int value);
    BinTree* find(int value);  // 查找
    void visit(BinTree* pNode);
    void preOrder(BinTree* root);  // 前序遍历
    void preOrder1(BinTree* root);  //  非递归前序遍历
    void inOrder(BinTree* root); // 中序遍历
    void inOrder1(BinTree* root); // 非递归中序遍历
    void inOrder2(BinTree* root); // 非递归中序遍历
    bool deleteNode(int value); // 删除节点
    
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in); // 重建二叉树
    

};

#endif /* defined(__acmer__biTree__) */
