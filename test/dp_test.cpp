//
//  dp_test.cpp
//  acmer
//
//  Created by 刘晓东 on 16/7/30.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "dp_test.hpp"


void edit_distance_test() {
    DynamicProgramming* dp = new DynamicProgramming;

    //    string word1 = "a";
    //    string word2 = "a";
    //    int a[9] = {-2, 2, -3, 4, -1, 2, 1, -5, 3};
    //    vector<int> input(a, a+9);
    //    int edit_distance = dp->maxSubArray(input);
    //    cout << edit_distance << endl;

    delete dp;
}

void maxProfitK_test(){
    int prices[] = {7, 1, 5, 3, 6, 4};
    
    DynamicProgramming* dp = new DynamicProgramming;
    
    int res = dp->maxProfitK2(prices, sizeof(prices)/sizeof(int), 3);
    
    cout << res << endl;
}

int cubicle_move_test(){
    
    const int M = 4;
    const int N = 5;
    
    vector<vector<int>> chess(M, vector<int>(N));
    
    //初始化棋盘
    int i,j;
    for (i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            chess[i][j] = rand() % 100;
        }
    }
    
    Printer::matrix_printer(chess, M, N);
    DynamicProgramming* dp = new DynamicProgramming;
    
    cout << dp->cubicle_move(chess, M, N) << endl;
    cout << dp->cubicle_move2(chess, M, N) << endl;
    delete dp;
    
    
    return 0;
}

/****************************
 *         走台阶测试         *
 ****************************/
int step_count_test() {
    int n;
    DynamicProgramming* dp= new DynamicProgramming;

    while(cin >> n) {
                cout << dp->step_count(n) << endl;
    }
    
    delete dp;
    return 0;
}

int charge_test() {
    int denomination[] = {1,2,5,10,20,50,100};
    
    int size = sizeof(denomination) / sizeof(int);
    int value = 200;
    DynamicProgramming* dp = new DynamicProgramming;
    
    int c = dp->charge(value, denomination, size);
    cout << c << endl;
    
    return 0;
}
