//
//  basic_arrays.cpp
//  acmer
//
//  Created by 刘晓东 on 16/9/5.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "basic_arrays.hpp"


int Basic_Arrays::countSum(int *arr, int len, int sum) {
    
    //sort
    for (int i = 0; i < len; i++) {
        cout << *(arr+i) << '\t';
    }
    cout << endl;
    
    sort(arr, arr+len);
    for (int i = 0; i < len; i++) {
        cout << *(arr+i) << '\t';
    }
    return 0;
}