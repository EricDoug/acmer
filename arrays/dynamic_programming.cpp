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
            if (A[i] == B[j]) {
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