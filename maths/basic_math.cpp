//
//  basic_math.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/23.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "basic_math.hpp"

bool isPrime(long x) {
    for (long i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
