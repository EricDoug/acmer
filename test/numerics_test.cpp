//
//  numerics_test.cpp
//  acmer
//
//  Created by 刘晓东 on 16/9/1.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "numerics_test.hpp"


int gcd_test() {
    
    int a, b;
    while(cin >> a >> b)
    {
        cout << gcd(a, b) << endl;
    }
    return 0;
}