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

// 素数伴侣
int prime_company();

// 水仙花数
bool is_shuixian(int x);
int shuixian_test();


#endif /* basic_math_hpp */
