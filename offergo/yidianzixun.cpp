//
//  yidianzixun.cpp
//  acmer
//
//  Created by EricDoug on 16/10/10.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "yidianzixun.hpp"



int calcThrowNumber(int numOfFloors,int numOfBalls){
    
    if(numOfFloors < 1 || numOfBalls < 1)
        return -1;
    
    if(numOfFloors == 1) return 0;
    if(numOfBalls == 1) return numOfFloors-1;
    
    vector<vector<int>> dp((numOfBalls+1),vector<int>((numOfFloors+1),0));
    
    int i,j,r;
    int tmp,min;
    for(i = 0;i <= numOfBalls;i++)
        dp[i][0]=dp[i][1] =0;
    for(j = 2;j<=numOfFloors;j++)
        dp[1][j]= j-1;
    
    for(i=2;i<=numOfBalls;i++){
        for(j = 2; j <= numOfFloors;j++){
            min = 65535;
            for(r = 1;r <=j;r++){
                tmp = max(dp[i-1][r],dp[i][j-r]) + 1;
                if(tmp < min)
                    min = tmp;
                
                
            }
            dp[i][j] = min;
        }
        
    }
    
    return dp[numOfBalls][numOfFloors];
}


int wanmei_1() {
    int n,k;
    while(cin >> n>> k){
        cout << calcThrowNumber(n,k) << endl;
    }
    
    return 0;
}




int yidian_2() {
    int n;
    while(cin >> n){
        vector<int> hurts(n,0);
        int max_hurts = 0;
        
        for(int i = 0;i < n;i++){
            cin >> hurts[i];
            max_hurts += hurts[i];
        }
        
        vector<int> max_index(n,0);
        
        int cur_hurts = -1;
        for(int j=1;j<n-1;j++){
            cur_hurts = hurts[j-1]+hurts[j] + hurts[j+1];
            max_index[j] = cur_hurts;
        }
        
        
        
        int res = 0;
        int die_num = n;
        while(1){
            int max_h=-1;
            int max_i = 1;
            bool is_zero = true;
            for(int i=1;i<n-1;i++){
                if(max_index[i] > max_h){
                    max_h = max_index[i];
                    max_i = i;
                }
                if(max_index[i] > 0 )
                    is_zero=false;
            }
            if(is_zero)
                break;
            else{
                max_hurts -= max_h;
                max_index[max_i-1] = 0;
                max_index[max_i] = 0;
                max_index[max_i+1] = 0;
                die_num -= 3 ;
                
                res += max_hurts;
            }
        }
        
        
        cout << res << endl;
        
    }
    return 0;
}

