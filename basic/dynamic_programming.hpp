//
//  dynamic_programming.hpp
//  acmer
//
//  Created by 刘晓东 on 16/7/25.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef dynamic_programming_hpp
#define dynamic_programming_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DynamicProgramming{
public:
    
//    DynamicProgramming();
//    ~DynamicProgramming();
    // 最长公共子串
    void lcs(const char* A, const char* B, string& common_s);
    
    //编辑距离
    int edit_distance(string word1, string word2);
    
    // 最大连续乘积子序列
    int mps(vector<int>& nums);
    
    // 最大子数组
    int maxSubArray(vector<int> nums);
    
    // 最大子数组2
    //int maxTwoSubArray(vector<int> nums);
    
    // 股票最大收益问题2
    int maxProfitK(const int* prices, int size, int K);
    
    // 改进的最多k次交易股票最大收益问题
    int maxProfitK2(const int* prices, int size, int K);
    
    // 走格子问题1
    int cubicle_move(vector<vector<int>>& chess, int M, int N);
    
    // 使用滚动数组解走格子问题
    int cubicle_move2(vector<vector<int>>& chess, int M, int N);
    
    
    
};

#endif /* dynamic_programming_hpp */
