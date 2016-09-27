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


#endif /* defined(__acmer__huawei__) */
