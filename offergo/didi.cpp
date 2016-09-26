//
//  didi.cpp
//  acmer
//
//  Created by EricDoug on 16/9/26.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "didi.hpp"

char num_char(int x){
    switch(x){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8:return '8';
        case 9:return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
    }
    return 'x';
}

int didi_1(){
    int M,N;
    while(cin >> M >> N){
        stack<int> s;
        int tmp = M;
        int a = 0;
        while(tmp){
            a = tmp % N;
            s.push(a);
            tmp /= N;
        }
        while(!s.empty()){
            a = s.top();
            cout << num_char(a);
            s.pop();
        }
        
    }
    return 0;
}

int didi_2() {
    
    int n,sum;
    while(cin >> n >> sum){
        vector<int> a(n,0);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        vector<vector<int>> dp(n,vector<int>(n));
        if(a[0] == sum)
            dp[0][0] = 1;
        int count = 0;
        int cur_sum = 0;
        for(int i = 1;i <=n;i++){
            for(int j=1;i <=n;j++){
                
                if((a[i]+a[j] ==sum))
                    dp[i][j] = dp[i-1][j-1] + 1;
                
            }
        }
        cout << dp[n][n] << endl;
    }
    return 0;
}

