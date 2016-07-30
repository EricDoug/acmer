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