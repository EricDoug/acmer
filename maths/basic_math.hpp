//
//  basic_math.hpp
//  acmer
//
//  Created by 刘晓东 on 16/8/23.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef basic_math_hpp
#define basic_math_hpp

#include "pre_func.h"

bool isPrime(long x);

// 质数因子
int prime_factor();

// 因数计数
int factor_count(int n);

// 小球落地
double getJourney(int high,int k);
double getKthHigh(int high,int k);


#endif /* basic_math_hpp */
