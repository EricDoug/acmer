//
//  offergo_test.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/1.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "offergo_test.hpp"
#include "printer.hpp"

int netease_weight_cmp_test() {
    // int input[4][2] = {{1,2},{2,4},{1,3},{4,3}};
    
    int g1 = 2, g2 = 3;
    vector<vector<int>> records(4, vector<int>(4));
    
    records[0][0] = 1;
    records[0][1] = 2;
    records[1][0] = 2;
    records[1][1] = 4;
    records[2][0] = 1;
    records[2][1] = 3;
    records[3][0] = 4;
    records[3][1] = 3;
    
//    int res = weight_cmp(g1, g2, records, 4);
//    
//    cout << res << endl;
    
    
    Printer::matrix_printer(records, 4, 2);
    
    
    
    //2,3,[[1,2],[2,4],[1,3],[4,3]],4
    return 0;
}


int netease_findkth_test()
{
    int input[] = {1,3,5,2,2};
    vector<int> x(input, input+5);
    
    Finder* finder = new Finder();
    int res = finder->findKth(x, 5, 3);
    cout << res << endl;
    return 0;
}