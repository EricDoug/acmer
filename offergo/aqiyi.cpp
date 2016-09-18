//
//  aqiyi.cpp
//  acmer
//
//  Created by EricDoug on 16/9/118
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "aqiyi.h"

int aiqiyi_1() {
    int rule;
    map<int,int> group_day;
    map<int,int> group_task;
    int sum = 0;
    while(cin >> rule){
        if(rule == 1){
            int start_day,end_day,val;
            cin >> start_day >> end_day >> val;
            for(int i=start_day;i <= end_day; i++){
                if(group_day[i]) {
                    group_day[i] = max(val, group_day[i]);
                }
                else{
                    group_day[i] = val;
                }
            }
        }
        else if(rule == 2){
            int day,val;
            cin >> day >> val;
            if(group_task[day])
                group_task[day] = max(val, group_task[day]);
            else
                group_task[day] = val;
        }
        
    }
    
    map<int,int>::iterator iter;
    for(iter=group_day.begin();iter!=group_day.end();++iter){
        sum += iter->second;
    }
    for(iter = group_task.begin();iter!=group_task.end();++iter){
        sum += iter->second;
    }
    cout << sum << endl;
    
    return 0;
}

int edit_distance(string word1,string word2) {
    int word1_len = word1.size();
    int word2_len = word2.size();
    
    if(word1_len == 0 && word2_len == 0)
        return 0;
    else if(word1_len == 0){
        return word2_len;
    }
    else if(word2_len == 0){
        return word1_len;
    }
    
    vector<vector<int>> d(word1_len+1, vector<int>(word2_len+1));
    
    for(int i = 0; i <=word1_len;i++)
        d[i][0] = i;
    for(int j = 0; j <= word2_len;j++)
        d[0][j] = j;
    
    for(int i = 1; i <= word1_len;i++) {
        for(int j = 1;j <= word2_len;j++) {
            int f;
            int temp = min(d[i-1][j] + 1, d[i][j-1] +1);
            
            if(word1[i-1] == word2[j-1]){
                f = 0;
            }
            else {
                f = 1;
            }
            
            d[i][j] = min(temp, d[i-1][j-1] + f);
        }
    }
    
    return d[word1_len][word2_len];
}


int aiqiyi_2() {
    string word1;
    string word2;
    string line;
    while(getline(cin, line)){
        //cout  << line << endl;
        
        //        int word1_len = word1.size();
        //        int word2_len = word2.size();
        stringstream ss;
        ss << line;
        ss >> word1 >> word2;
        ss.clear();
        
        
        
        cout << edit_distance(word1,word2) << endl;
    }
    
    return 0;
}
