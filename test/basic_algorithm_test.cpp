//
//  basic_algorithm_test.cpp
//  acmer
//
//  Created by EricDoug on 16/9/27.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "basic_algorithm_test.hpp"


int countWays_test() {
    int n;
    Recursion* recur = new Recursion();
    while (cin >> n) {
        cout << recur->countWays(n) << endl;
    }
    delete recur;
    
    return 0;
}
