//
//  gcd.cpp
//  acmer
//
//  Created by 刘晓东 on 16/9/1.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "gcd.hpp"

/**************************
 *       最小公约数         *
 **************************/
int gcd(int a, int b) {
    if(a < b)
        swap(a, b);
    
    int t;
    while(t = a%b) {
        a = b;
        b = t;
    }
    return b;
}