//
//  netease.hpp
//  acmer
//
//  Created by 刘晓东 on 16/8/1.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef netease_hpp
#define netease_hpp

#include "pre_func.h"

// 比较重量
class Cmp {

public:
    int weight_cmp(int g1, int g2, vector<vector<int>> records, int n);

};
// 寻找第K大数
class Finder {
public:
    int findKth(vector<int>& a, int n, int K);
    
    int quickFind(vector<int>& a,int left, int right, int k);
};

// 二叉树

#endif /* netease_hpp */
