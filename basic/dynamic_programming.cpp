//
//  dynamic_programming.cpp
//  acmer
//
//  Created by 刘晓东 on 16/7/25.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "dynamic_programming.hpp"

using namespace std;

/**************************
 *     最大公共子序列       *
 **************************/
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

/**************************
 *       编辑距离          *
 **************************/
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


/**************************
 *     乘积最大子序列       *
 **************************/
int DynamicProgramming::mps(vector<int>& nums) {
    int nums_len = (int)nums.size();
    int max_res;
    
    int *max_product = new int[nums_len];
    int *min_product = new int[nums_len];
    
    // 初始化边界
    max_product[0] = min_product[0] = nums[0];
    max_res = nums[0];
    
    int i;
    for (i = 1; i < nums_len; i++) {
        max_product[i] = max(max_product[i-1] * nums[i], nums[i]);
        max_product[i] = max(max_product[i], min_product[i-1] * nums[i]);
        min_product[i] = min(min_product[i-1] * nums[i], nums[i]);
        min_product[i] = min(max_product[i-1] * nums[i], min_product[i]);
        
        if(max_product[i] > max_res){
            max_res = max_product[i];
        }
    }
    
    delete[] max_product;
    delete[] min_product;
    
    return max_res;
}

/**************************
 *       最大子数组         *
 **************************/
int DynamicProgramming::maxSubArray(vector<int> nums){
    
    int nums_size = (int)nums.size();

    int max_res;
    int *max_array = new int[nums_size];
    
    // 初始化边界
    max_array[0] = nums[0];
    max_res = nums[0];
    
    for (int i = 1; i < nums_size; i++) {
        max_array[i] = max(nums[i], max_array[i-1] + nums[i]);
        
        if (max_array[i] > max_res) {
            max_res = max_array[i];
        }
    }
    
    delete[] max_array;
    
    return max_res;
    
}


/**************************
 *       最大子数组2        *
 **************************/


/**************************
 *      股票最大收益2       *
 **************************/
int DynamicProgramming::maxProfitK(const int* prices,int size,int K)
{
    
    vector<vector<int>> dp(K+1, vector<int>(size, 0));
    
    
    int i,j,k;
    
    for (k = 1; k <= K; k++)
    {
        for (i = 1; i < size; i++)
        {
            dp[k][i] = dp[k][i-1];
            for(j = 0; j < i; j++)
            {
                dp[k][i] = max(dp[k][i], dp[k-1][j] + prices[i] - prices[j]);
            }
        }
    }
    
    return dp[K][size-1];
}


/**************************
 *    改进股票最大收益2      *
 **************************/
int DynamicProgramming::maxProfitK2(const int*prices, int size, int K){
    vector<vector<int>> dp(K+1, vector<int>(size, 0));
    
    int k,i;
    int mx;
    
    for (k = 1; k <= K; k++) {
        mx = dp[k-1][0] - prices[0];
        for (i = 1; i < size; i++) {
            dp[k][i] = max(dp[k][i-1], mx + prices[i]);
            mx = max(mx, dp[k-1][i] - prices[i]);
        }
    }
    
    return dp[K][size - 1];
}

/**************************
 *        走格子问题        *
 **************************/
int DynamicProgramming::cubicle_move(vector<vector<int>>& chess, int M, int N)
{
    vector<vector<int>> dp(M, vector<int>(N));
    int i,j,k;
    // 初始化
    for(i=0; i<M; i++)
    {   int sum = 0;
        for(k = 0; k <= i; k++)
        {
            sum += chess[k][0];
        }
        dp[i][0] = sum;
    }
    for(j = 0; j < N; j++ )
    {
        int sum = 0;
        for(k = 0; k <= j; k++)
        {
            sum += chess[0][k];
        }
        dp[0][j] = sum;
    }
    for(i = 1; i < M; i++)
    {
        for (j = 1; j < N; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + chess[i][j];
        }
    }
    return dp[M-1][N-1];
}

int DynamicProgramming::cubicle_move2(vector<vector<int>>& chess, int M, int N)
{
    // 使用与列相等的行存储状态
    vector<int> dp(N);
    // 初始化
    int i,j;
    dp[0] = chess[0][0];
    for (j = 1; j < N; j++) {
        dp[j] = dp[j-1] + chess[0][j];
    }
    // 依次计算每行
    for (i = 1; i < M; i++)
    {
        // 更新当前行的首状态
        dp[0] += chess[i][0];
        for (j = 1; j < N; j++)
        {
            // 取上方或者左边最小的数
            if ( dp[j-1] < dp[j])
            {
                dp[j] = dp[j-1] + chess[i][j];
            }
            else {
                dp[j] += chess[i][j];
            }
        }
    }
    return dp[N-1];
}

/*******************************
 *           走台阶             *
 *******************************/
int DynamicProgramming::step_count(int n) {
    
    if(n == 1)
        return 1;
    
    if(n == 2)
       return 2;
    
    if(n == 3)
       return 4;
       
    if(n >= 4)
       return step_count(n-3) + step_count(n-2) + step_count(n-1);
       
    return 0;
}

