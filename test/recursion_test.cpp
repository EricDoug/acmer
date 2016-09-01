//
//  recursion_test.cpp
//  acmer
//
//  Created by EricDoug on 16/7/31.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "recursion_test.h"

int sqrt_test() {
    
    Recursion* recursion = new Recursion;
    
    for (int i = 0; i <= 10; i++) {
        cout << recursion->mysqrt((double)i) << endl;
    }
    
    delete recursion;
    
    return 0;
}



int recur_count_test() {
    
    Recursion* recursion = new Recursion;
    recursion->recur_count(8);
    cout << recursion->getCnt() << endl;
    
    return 0;
}