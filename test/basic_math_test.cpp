//
//  basic_math_test.cpp
//  acmer
//
//  Created by 刘晓东 on 16/9/5.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "basic_math_test.hpp"

/****************************
 *         因数计数          *
 ***************************/
int factor_count_test() {
    int n;
    while (cin >> n) {
        cout << factor_count(n) << endl;
    }
    
    return 0;
}

/*****************************
 *        小球落地测试         *
 *****************************/
int throw_ball() {
    int high;
    while(cin >> high) {
        cout << getJourney(high, 5) << endl;
        cout << getKthHigh(high, 5) << endl;
    }
    return 0;
}
