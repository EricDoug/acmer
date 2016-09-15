//
//  meituan.cpp
//  acmer
//
//  Created by EricDoug on 16/9/11.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "meituan.h"
#include <sstream>



int lcs(string s1,string s2){
    int s1_len = s1.length();
    int s2_len = s2.length();
    
    int chess[s1_len+1][s2_len+1];
    
    for (int i = 0; i <= s1_len; i++) {
        chess[i][0] = 0;
    }
    for(int j = 0; j <= s2_len; j++){
        chess[0][j] = 0;
    }
    
    int max = -1;
    for(int i = 1; i <= s1_len; i++){
        for (int j = 1; j <= s2_len; j++) {
            if(s1[i-1] == s2[j-1]){
                chess[i][j] = chess[i-1][j-1] + 1;
            }
            else {
                chess[i][j] = 0;
            }
            
            if(chess[i][j] > max){
                max = chess[i][j];
            }
        }
    }
    
    return max;
}


/**************
 * @func: 最大收益
 * @input: 2
           1,3,2
           4,2,5
   @output: 
           1,3
           6
 **************/

void max_profit() {
    int k;
    while (cin >> k) {
        string input;
        cin >> input;
        stringstream ss;
        ss.str(input);
        deque<int> sites;
        
        while (1) {
            int site;
            char dot;
            if (ss.fail()) {
                break;
            }
            ss >> site >> dot;
            // cout << site << endl;
            // cout << dot << endl;
            sites.push_back(site);
        }
        
        int site_size = sites.size();
        vector<int> site_price(site_size+1,0);
        
        ss.clear();
        input.erase();
        cin >> input;
        ss.str(input);
        while (1) {
            int price;
            char dot;
            if(ss.fail()) {
                break;
            }
            ss >> price >> dot;
            int site;
            site = sites.front();
            site_price[site]=price;
            // cout << price << endl;
            sites.pop_front();
        }
        
        ss.clear();
        input.erase();
        
        int max = -1;
        int max_site[2] = {0};
        for (int i = 1; i <= site_size; i++) {
            for(int j = i+k; j <= site_size; j++){
                int price_sum = site_price[i] + site_price[j];
                if(price_sum > max) {
                    max = price_sum;
                    max_site[0] = i;
                    max_site[1] = j;
                }
            }
        }
        
        cout << max_site[0] << "," << max_site[1] << endl;
        cout << max << endl;
        
        
    }
    
}