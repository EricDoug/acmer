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
    
    DynamicProgramming();
    ~DynamicProgramming();
    // 最长公共子串
    void lcs(const char* A, const char* B, string& common_s);
    
private:
    
    
    
    
};

#endif /* dynamic_programming_hpp */
