//
//  basic_graph.cpp
//  acmer
//
//  Created by EricDoug on 16/9/118
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "basic_graph.h"

int find_road() {
    int n,a,b;
    while (cin >> n >> a >> b) {
        int** map = new int*[n];
        int* visit = new int[n];
        int* que = new int[n];
        
        for (int i=0; i<n; i++)
        {
            map[i] = new int[n];
            visit[i] = 0;
        }
        
        for (int i=0; i<n; i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> map[i][j];
            }
        }
        
        int top=-1,tail = -1;
        int cur,count = 0;
        que[++tail] = a;
        visit[a] = 1;
        while (top != tail)
        {
            cur = que[++top];
            for(int i=0;i<n;i++)
            {
                if(map[cur][i]==1 && visit[i] == 0 && i != b)  // 有路就加入队列
                {
                    que[++tail]=i;
                    visit[i] = 1;
                }
                else if(map[cur][i] == 1 && i == b)
                {
                    count++;
                }
            }
        }
        
        cout << count << endl;
        delete[] que;
        delete[] visit;
        for (int i=0; i<n; i++) {
            delete[] map[i];
        }
    }
    return 0;
}
