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
    
    string word1 = "a";
    string word2 = "a";
    int edit_distance = dp->edit_distance(word1, word2);
    cout << edit_distance << endl;
    
    
    return 0;
}
