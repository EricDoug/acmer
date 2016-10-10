//
//  wap.cpp
//  acmer
//
//  Created by EricDoug on 16/9/30.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "wap.hpp"

int ovalue[1010];
int value[1010];

struct Room
{
    int to;
    int next;
    
};

Room node[1010];
int head[10100];

int wap_2()
{
    int N,M;
    int n1,n2;
    int t1,t2,t3;
    int maximum;
    int edgecount;
    while(cin >> N >> M)
    {
        vector<int> s(N,0);
        maximum = 0;
        edgecount = 0;
        for(int i = 1; i<=N; i++)
        {
            cin >> s[i];
            ovalue[i] = value[i];
            head[i] = -1;
        }
        
        for(int i = 0; i<N - 1; i++)
        {
            cin>>n1>>n2;
            t1 = ovalue[n1];
            value[n1] += ovalue[n2];
            value[n2] += t1;
            node[edgecount].to = n2;
            node[edgecount].next = head[n1];
            head[n1] = edgecount;
            edgecount ++;
            node[edgecount].to = n1;
            node[edgecount].next = head[n2];
            head[n2] = edgecount;
            edgecount ++;
        }
        while(M--)
        {
            t2 = 0;
            for(int i = 1 ; i<= N; i++)
            {
                if(value[i] > t2) {t2 = value[i]; t3 = i;}
            }
            maximum += t2;
            t3=0;
            value[t3] = -1;
            for(int i = head[t3]; i!=-1; i = node[i].next)
            {
                value[node[i].to] -= ovalue[node[i].to];
            }
        }
        cout<<maximum<<endl;
    }
    return 0;
}
