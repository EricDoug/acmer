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


/********************************
 *            链表翻转            *
 ********************************/
struct node {
    int m;
    node *next;
    node(int x): m(x),next(NULL) {}
};

// 新建链表序列
ListNode* create(int num);
// 单链表翻转
ListNode* reverseList(ListNode* head);
// 打印单链表
void printList(ListNode* head);
/**********************************
 *             链表逆序进阶         *
 **********************************/
// 逆序k个
ListNode* reverseKthList(ListNode* head, int k);

//链表相邻元素翻转
int reverse_adj_list();

/***********************************
 *            字符操作相关           *
 ***********************************/
// 去掉大写、小写、数字字符
int duplicate_some();

// 字符统计
string int2string(int m);
int character_stat();



#endif /* defined(__acmer__huawei__) */
