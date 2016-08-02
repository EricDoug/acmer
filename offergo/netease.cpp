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
    
    int big_num = right - i;
    
    if (k - big_num - 1 == 0)
    {
        return pivot;
    }
    else if (k - big_num - 1 > 0){
        return quickFind(a, left, i - 1, k - big_num -1);
    }
    else {
        return quickFind(a, i + 1, right, k);
    }
    
}


int Finder::findKth(vector<int>& a,int n, int K) {
    return quickFind(a, 0, n - 1, K);
}