//
//  recursion_test.cpp
//  acmer
//
//  Created by EricDoug on 16/7/31.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "recursion_test.h"

int recursion_test() {
    
    Recursion* recursion = new Recursion;
    
    for (int i = 0; i <= 10; i++) {
        cout << recursion->mysqrt((double)i) << endl;
    }
    
    delete recursion;
    
    return 0;
}