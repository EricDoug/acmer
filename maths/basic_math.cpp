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

int factor_count(int n) {
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }
    
    return count;
}
/***********************************
 *        小球落地所走路程            *
 ***********************************/
double getJourney(int high,int k){
    double res = high;
    for(int i=1;i<k;i++){
        res += (high/(pow(2.0,i-1)));
    }
    return res;
}


double getKthHigh(int high,int k){
    return high/(pow(2.0,k));
}


