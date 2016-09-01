//
//  recursion.cpp
//  acmer
//
//  Created by EricDoug on 16/7/31.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "recursion.h"

/********************************
 *             倒数              *
 ********************************/
double Recursion::reciprocal(double a)
{
    double x = 1;
    
    while (a * x >= 2)
    {
        if (a > 1)
            x /= 10;
        else
            x *= 10;
        
        
    }
    double t = a;
    while (fabs(x-t) > 1e-6)
    {
        t = x;
        x = x * (2 - a * x);
    }
    return x;
}


/********************************
 *           平方根              *
 ********************************/
double Recursion::mysqrt(double a)
{
    if (a < 1e-6) {
        return 0;
    }
    
    double x = 1;
    while (a * x * x >= 3)
    {
        x *= 0.1;
    }
    double t = a;
    while (fabs(x - t) > 1e-6)
    {
        t = x;
        x = (3 - a * t * t) * t/2;
    }
    
    return reciprocal(x);
}

/*******************************
 *        使用递归算平方根        *
 *******************************/
double Recursion::sqrt_recur(double a) {
    if (a < 1e-6) {  // 负数或者0， 则直接返回0
        return 0;
    }
    
    double x = a / 2;
    double t = a;
    
    // 使用递归
    while (fabs(x - t) > 1e-6) {
        t = x;
        x = (x+a/x) / 2;
    }
    return x;
    
}

/******************************
 *        计算迭代次数          *
 ******************************/
int Recursion::recur_count(int n) {
    cnt++;
    if (n == 0) {
        return 1;
    } else if(n == 1) {
        return 2;
    }
    else
        return recur_count(n-1) + recur_count(n-2);
}

int Recursion::getCnt() {
    return this->cnt;
}