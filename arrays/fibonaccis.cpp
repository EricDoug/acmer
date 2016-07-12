//
//  fibonaccis.cpp
//  acmer
//
//  Created by 刘晓东 on 16/7/12.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "fibonaccis.hpp"

int fibonacci_recursive(int n) {
    
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
    }
}


int find_nth_fibonacci(int n) {
    
    if (n == 1) {
        return 0;
    }else if (n == 2 || n == 3) {
        return 1;
    }
    
    // 从第四项开始，需要计算
    int s1 = 1;
    int s2 = 1;
    int i = 4;
    int sum = 0;
    while (i <= n) {
        sum = s1 + s2;
        s1 = s2;
        s2 = sum;
        i++;
    }
    
    return sum;
}

