//
//  huawei.h
//  acmer
//
//  Created by 刘晓东 on 16/9/23.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef __acmer__huawei__
#define __acmer__huawei__

#include "pre_func.h"
#include "linked_list.hpp"
#include <stack>
using namespace std;

/**********************************
 *             学英语              *
 **********************************/
string num_egword(int x);
int xueyingyu();


/*********************************
 *           迷宫问题             *
 *********************************/
struct Node {
    int x;
    int y;
    Node(int x_v, int y_v): x(x_v),y(y_v) {}
};

struct BNode {
    int x,y;
    int prex,prey;
    BNode(int x_v, int y_v): x(x_v),y(y_v) {}
};

// 使用深度度优先搜索解迷宫
int maze_dfs();
// 使用广度优先搜索解迷宫
int maze_bfs();

// 名字漂亮度
int pretty_name();

// 输出单向链表中倒数第k个结点
int outputkthNode();
void printLinkedList(ListNode* head);

/********************************
 *            链表翻转            *
 ********************************/
struct node {
    int m;
    node *next;
    node(int x): m(x),next(NULL) {}
};



#endif /* defined(__acmer__huawei__) */
