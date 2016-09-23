//
//  baidu.cpp
//  acmer
//
//  Created by EricDoug on 16/9/118
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "baidu.h"



int baidu_1() {
    string s;
    while(cin >> s){
        int len = s.length();
        if(len <= 0){
            cout << 0 << endl;
            return 0;
            
        }
        map<char,int> char_bag;
        for(int i = 0; i < len; i++) {
            int num = 0;
            if(char_bag[s[i]]){
                for(int j = i+1;j < len;j++){
                    if(s[i]== s[j]){
                        num++;
                    }
                    char_bag[s[i]] = max(char_bag[s[i]], num);
                }
            }
            else {
                char_bag[s[i]] = 1;
                for(int j = i+1; j < len;j++){
                    if(s[i]== s[j]){
                        num++;
                    }
                    char_bag[s[i]] = num;
                }
            }
        }
        
        int res = 0;
        map<char,int>::iterator iter;
        for(iter=char_bag.begin();iter!=char_bag.end();++iter){
            res += iter->second;
        }
        cout << res << endl;
    }
    
    return 0;
}


int six_2() {
    char mat[3][3];
    for(int i=0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> mat[i][j];
            
        }
    }
    
    for(int i=0;i < 3;i++){
        for(int j=0;j < 3-j;j++){
            if(mat[i][j] != mat[j][i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    cout << "YES" << endl;
    return 0;
}

bool is_sup(int n){
    int a = n;
    int temp = 0;
    while(a){
        temp = a %10;
        if(temp != 0 && temp != 1)
            return false;
        a /=  10;
    }
    return true;
}

int six_1() {
    int n;
    
    while (cin >> n) {
        int count = 0;
        for(int i = 1; i<= n;i++){
            if(is_sup(i))
                count++;
        }
        cout << count << endl;
        
    }
    return 0;
}
