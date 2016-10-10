//
//  microsoft.cpp
//  acmer
//
//  Created by EricDoug on 16/10/10.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "microsoft.hpp"

int microsoft_1() {
    int N;
    int sum;
    int flag;
    int u;
    int t,c;
    while(cin>>N)
    {
        sum = N;
        flag = 1;
        u = 0;
        for(int i = 0; i<N; i++)
        {
            cin>>num[u][i];
        }
        while(flag)
        {
            flag = 0;
            for(int i = 0; i<N-1; i++)
            {
                if((num[u][i] + num[u][i+1])%2 != 0)
                {
                    flag = 1;
                    sum -= 2;
                    num[u][i] = -1;
                    num[u][i+1] = -1;
                    i++;
                }
            }
            if(flag)
            {
                t =(u+1)%2;
                c = 0;
                for(int i = 0; i<N; i++)
                {
                    if(num[u][i] >= 0)
                    {
                        num[t][c] = num[u][i];
                        c++;
                    }
                }
                u = t;
                N = sum;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
