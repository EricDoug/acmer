//
//  toutiao.cpp
//  acmer
//
//  Created by EricDoug on 16/10/2.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "toutiao.hpp"


void reverseString(string& s, int from, int to)
{
    while (from < to)
    {
        swap(s[from++], s[to--]);
    }
}

void leftRotateString(string& s, int n, int m)
{
    m %= n;
    reverseString(s, 0, m - 1);
    reverseString(s, m, n - 1);
    reverseString(s, 0, n - 1);
    
}



int toutiao_2() {
    string s;
    while(cin >> s){
        int count = 0;
        int len = s.length();
        
        for(int i=0;i<len;i++){
            string s_rotate = s;
            leftRotateString(s_rotate, len, i);
            if(s_rotate == s)
                count++;
            
        }
        cout << count << endl;
    }
    
    return 0;
}

void sort_nums(int cur, int n, vector<int>& res){
    if(cur > n)
        return;
    res.push_back(cur);
    for(int i = 0;i <= 9;i++){
        if(cur * 10 + i <= n){
            sort_nums(cur*10+i,n,res);
        }
        else
            break;
    }
}

int toutiao_1(){
    
    int n,m;
    while(cin >> n >> m){
        vector<int> res;
        for(int i =1;i <=n;i++){
            sort_nums(i,n,res);
        }
        cout << res[m-1] << endl;
    }
    
    return 0;
    
}

int num_dict(int n, int m) {
    
    vector<int> res;
    int i = 1, j;
    int k;
    for(;;)
    {
        
        for(k = 0; i*pow(10,k) <= n; ++k)
            res.push_back(i*pow(10,k));
        
        
        for(j = res.back()+1; j <= n && (j % 10) != 0; ++j)
            res.push_back(j);
        
        
        if(j % 10 == 0)
        {
            j--;
        }
        else
        {
            j /= 10;
        }
        
        
        while(j % 10 == 9)
            j /= 10;
        
        i = j+1;
        
        if(res.size() >= n) break;
    }
    return res[m-1];
}

int toutiao_11(){
    int n,m;
    while(cin >> n >> m){
        vector<int> res(n);
        int cur = 1;
        for(int i =0;i <n;i++){
            res[i] = cur;
            if(cur * 10 <= n){
                cur *= 10;
            }else{
                if(cur >= n)
                    cur /= 10;
                cur += 1;
                while(cur % 10 == 0)
                    cur /= 10;
            }
        }
        cout << res[m-1] << endl;
    }
    
    return 0;
}
