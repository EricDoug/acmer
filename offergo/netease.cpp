//
//  netease.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/1.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "netease.hpp"


int Finder::quickFind(vector<int> &a, int left, int right, int k)
{
    int i = left;
    int j = right;
    int pivot = a[left];
    
    while (i < j)
    {
        while (i < j && a[j] >= pivot)
            --j;
        if(i < j)
        {
            a[i++] = a[j];
        }
        while (i < j && a[i] <= pivot) {
            ++i;
        }
        if (i < j)
        {
            a[j--] = a[i];
        }
    }
    a[i] = pivot;
    
    
    
}