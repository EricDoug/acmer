//
//  camping_trip.cpp
//  acmer
//
//  Created by 刘晓东 on 16/6/19.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "camping_trip.hpp"


int n;
bool areFriends[10][10];
//若第taken[i]=i个学生找到了伙伴，则返回true,否则返回false.

int countPairings(bool taken[10]) {
    
    
    //初始部分：所有学生都找到了伙伴，那么已找出一种组合方式，故终止。
    bool finished = true;
    for(int i = 0; i < n; ++i)
        if (!taken[i]) {
            finished = false;
        }
    
    if (finished) {
        return 1;
    }
    
    int ret = 0;
    
    
    // 查找两名朋友关系的学生并组队。
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(!taken[i] && !taken[j] && areFriends[i][j]){
                taken[i] = taken[j] = true;
                ret += countPairings(taken);
                taken[i] = taken[j] = false;
            }
    return ret;
}