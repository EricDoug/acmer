//
//  dynamic_programming.cpp
//  acmer
//
//  Created by 刘晓东 on 16/7/25.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "dynamic_programming.hpp"

using namespace std;

void DynamicProgramming::lcs(const char* A, const char* B, string& common_s) {
    int A_size = (int)strlen(A);
    int B_size = (int)strlen(B);
    
    const char* s1 = A - 1;
    const char* s2 = B - 1;
    
    vector<vector<int>> chess(A_size, vector<int>(B_size+1));
    
    int i,j;
    // 初始化
    for(i = 0; i <= A_size; i++) {
        chess[i][0] = 0;
    }
    
    for (j = 0; j <= B_size; j++) {
        chess[0][j] = 0;
    }
    
    for (i = 1; i <= A_size; i++) {
        for (j = 1; j <= B_size; j++) {
            if (s1[i] == s2[j]) {
                chess[i][j] = chess[i-1][j-1] + 1;
            }
            else{
                chess[i][j] = max(chess[i][j-1], chess[i-1][j]);
            }
        }
    }
    
    
    
    i = A_size;
    j = B_size;
    
    while ((i != 0) && (j != 0)) {
        if (s1[i] == s2[j]) {
            common_s.push_back(s1[i]);
            i--;
            j--;
        }
        else {
            if (chess[i][j-1] > chess[i-1][j]) {
                j--;
            }
            else
                i--;
        }
    }
    
    reverse(common_s.begin(), common_s.end());
    
}


int DynamicProgramming::edit_distance(string word1, string word2) {
    
    int word1_len = (int)word1.size();
    int word2_len = (int)word2.size();
    
    if (word1_len == 0 && word2_len == 0) {
        return 0;
    }else if (word1_len == 0 ){
        return word2_len;
    }else if(word2_len == 0) {
        return word1_len;
    }
    
    // 使用二维数组存储状态
    vector< vector<int>> d(word1_len+1, vector<int>(word2_len+1));
    
    // 初始化边界
    for (int i = 0; i < word1_len; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < word2_len; j++) {
        d[0][j] = j;
    }
    
    
    // 使用递推式求
    for (int i = 1; i <= word1_len; i++) {
        for (int j = 1; j <= word2_len; j++) {
            int f;
            int temp = min(d[i-1][j] + 1, d[i][j-1] + 1);
            
            if(word1[i-1] == word2[j-1]) {
                f = 0;
            }else {
                f = 1;
            }
            
            d[i][j] = min(temp, d[i-1][j-1] + f);
        }
    }
    
    return d[word1_len][word2_len];
}