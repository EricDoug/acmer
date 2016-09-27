//
//  huawei.cpp
//  acmer
//
//  Created by EricDoug on 16/9/118
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "huawei.h"

// 学英语
string num_egword(int x){
    switch(x){
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
    
    return "error";
}

string num_cell(int x){
    switch (xueyingyu()) {
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 30: return "thirty";
        case 40: return "forty";
        case 50: return "fifty";
        case 60: return "sixty";
        case 70: return "seventy";
        case 80: return "eighty";
        case 90: return "ninety";
        case 100: return "hundred";
        case 1000: return "thousand";
    }
    
    return "error";
}



int xueyingyu(){
    long x;
    while (cin >> x) {
        if(x <= 0){
            cout << "error" << endl;
            return 1;
        }
        cout << x;
        stack<int> num_bag;
        int tmp = x;
        int a = 0;
        while(tmp){
            a = tmp/10;
            num_bag.push(a);
            tmp /= 10;
        }
        int len = num_bag.size();
        while(!num_bag.empty()){
            int num;
            if(len <= 1){
                num = num_bag.top();
                num_bag.top();
                cout << num_egword(x) << endl;
                len--;
            }
            if (len <= 2) {
                
            }
        }
        
        
    }
    
    return 0;
}

// 迷宫问题
int maze_dfs() {
    int m,n;
    while(cin >> m >> n){
        vector<vector<int>> map(m, vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        Node* startNode = new Node(0,0);
        Node* endNode = new Node(m-1,n-1);
        
        stack<Node*> s;
        s.push(startNode);
        visited[startNode->x][startNode->y] = 1;
        int step[][2] = {{1,0}, {0,1}};
        while (!s.empty())
        {
            bool flag = false;
            Node* curNode = s.top(); // 取当前节点
            if(curNode->x == endNode->x && curNode->y == endNode->y)
            {
                break;  // 如果到出口了，退出
            }
            else
            {
                for(int i=0;i<2;i++)
                {
                    Node* nextNode = new Node(curNode->x+step[i][0], curNode->y+step[i][1]);
                    if(nextNode->x >=0 && nextNode->x < m && nextNode->y >= 0 && nextNode->y <n
                       && map[nextNode->x][nextNode->y] == 0 && visited[nextNode->x][nextNode->y] == 0)
                    {
                        s.push(nextNode);
                        visited[nextNode->x][nextNode->y] = 1;
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    continue;
            }
           
            s.pop();
            
        }
        stack<Node*> reverseS;
        while (!s.empty()) {
            Node* curNode = s.top();
            reverseS.push(curNode);
            s.pop();
        }
        
        while (!reverseS.empty()) {
            Node* curNode = reverseS.top();
            cout << "(" << curNode->x << "," << curNode->y << ")" << endl;
            reverseS.pop();
        }
        
        
    }
    
    return 0;
}





