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



/********************************
 *             上台阶            *
 ********************************/
int Recursion::countWays(int n){
    
    
    map[0] = 0;
    map[1] = 1;
    map[2] = 2;
    map[3] = 4;
    if(n<=0)
        return map[0];
    if(n==1)
        return map[1];
    if(n == 2)
        return map[2];
    if(n == 3)
        return map[3];
    for(int i=4;i<=n;i++)
        map[i] = ((map[i-1]+map[i-2]) % 1000000007 + map[i-3]) % 1000000007;
    return map[n];
    
}

/*********************************
 *          机器人走方格           *
 *********************************/
int Recursion::robot_walk1(int x, int y) {
    vector<vector<int>> dp(x,vector<int>(y,1));
    
    for(int i = 1;i<x;i++){
        for(int j =1;j<y;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[x-1][y-1];
}
/********************************
 *      机器人走带陷阱的方格        *
 ********************************/
int Recursion::robot_walk2(vector<vector<int> > map, int x, int y){
    
    vector<vector<int>> dp(x,vector<int>(y,0));
    
    for(int i=0;i<x;i++){
        for(int j = 0; j<y;j++){
            if(map[i][j]!=1){
                continue;
            }
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i!=0&& j==0){
                dp[i][0] = dp[i-1][0];
            }
            else if(i==0 && j != 0){
                dp[0][j] = dp[0][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[x-1][y-1];
}
