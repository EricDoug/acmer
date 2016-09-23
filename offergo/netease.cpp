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



int net_2 () {
    
    int N,M,t1,t2;
    while(cin >> N >> M >> t1 >>t2) {
        map<int,vector<int>> mat;
        for(int i = 0;i < M;i++) {
            int x,y;
            cin >>x>> y;
            mat[x].push_back(y);
        }
        deque<int> q;
        
        if(!mat[t1].empty()){
            for(int i=0;i < mat[t1].size();i++){
                
                q.push_back(mat[t1][i]);
            }
        }
        int count = 0;
        while(!q.empty()){
            int tmp = q.front();
            q.pop_front();
            if(tmp==t2)
                count++;
            else{
                for(int i=0;i < mat[tmp].size();i++){
                    q.push_back(mat[tmp][i]);
                }
            }
        }
        cout << count << endl;
        
    }
    
    
    return 0;
}

int net_1() {
    int n,a,b;
    while(cin >> n >> a >> b){
        vector<int> h(n,0);
        for(int i=0;i < n;i++){
            cin >> h[i] ;
        }
        
        int min_fire = 0;
        vector<int> visit(n,0);
        for(int i=1;i < n-1;i++){
            while(h[i]>=0 || h[i-1] >=0 || h[i+1] >= 0){
                min_fire++;
                h[i] -=a;
                h[i-1] -= b;
                h[i+1] -= b;
                visit[i]++;
            }
        }
        cout << min_fire << endl;
        for(int i = 0;i<n;i++){
            while(visit[i]){
                cout << i+1 << ' ';
                visit[i]--;
            }
        }
    }
    
    return 0;
}
