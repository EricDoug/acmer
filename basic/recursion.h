//
//  recursion.h
//  acmer
//
//  Created by EricDoug on 16/7/31.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#ifndef __acmer__recursion__
#define __acmer__recursion__

#include "pre_func.h"

class Recursion {
private:
    int map[100000];
    
public:
//    Recursion();
//    ~Recursion();
    
    // 平方根算法
    double mysqrt(double a);
    
    // 使用递归算平方根
    double sqrt_recur(double a);
    
    // 倒数算法
    double reciprocal(double a);
    
    // 计算迭代次数
    int recur_count(int n);
    
    // 上楼梯
    int countWays(int n);
    
    int getCnt();
    
    // 机器人走方格
    int robot_walk1(int x,int y);
    
    // 机器人走带陷阱的方格
    int robot_walk2(vector<vector<int> > map, int x, int y);
    
private:
    int cnt=0;
    
};

#endif /* defined(__acmer__recursion__) */
