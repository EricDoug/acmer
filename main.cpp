//
//  main.cpp
//  acmer
//
//  Created by 刘晓东 on 16/6/19.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "pre_func.h"
#include "dp_test.hpp"
#include "recursion_test.h"
#include "offergo_test.hpp"
#include "strings_test.hpp"
#include "deques.hpp"
#include "numerics_test.hpp"
#include "basic_math_test.hpp"
#include <fstream>
#include <math.h>
#include "ip_masks.h"


int rank_array(int* a, int len) {
    
    int temp;
    for(int i = len-1; i >= 0; i--) {
        temp = a[i];
    }
    return 0;
}








int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //cubicle_move_test();
    //sqrt_test();
    //netease_weight_cmp_test();
    
//    netease_findkth_test();
    //left_rotate_test();
    
    //permutation_test();
    //spaceReplace_test();
    
    // regMatch_test();
    // isNumeric_test();
    
    //hex2decimal_test();
    //getDuplicateNum();
    //reverseSentence_test();
    
    //filereader();
    //B_small();
    
//    recog_ip_mask_test();
    //gcd_test();
    //recur_count_test();
    // step_count_test();
    //factor_count_test();
    check_ip_network();
    
    
    return 0;
}
