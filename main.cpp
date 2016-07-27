//
//  main.cpp
//  acmer
//
//  Created by 刘晓东 on 16/6/19.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include <iostream>
# include "dynamic_programming.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    DynamicProgramming* dp = new DynamicProgramming;
    
//    string word1 = "a";
//    string word2 = "a";
    int a[8] = {1,0,-1,2,3,-5,-2};
    vector<int> input(a, a+8);
    int edit_distance = dp->mps(input);
    cout << edit_distance << endl;
    
    
    return 0;
}
