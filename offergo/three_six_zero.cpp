//
//  three_six_zero.cpp
//  acmer
//
//  Created by 刘晓东 on 16/9/10.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "three_six_zero.hpp"


int test_1() {
    
    int t,maxMem;
    while(cin >> t >> maxMem) {
        vector<int> mem;
        for(int i=0;i<t;i++){
            string oper;
            int mem_size;
            cin >> oper >> mem_size;
            if(oper == "new"){
                if(find(mem.begin(),mem.end(), mem_size) == mem.end()){
                    mem.push_back(mem_size);
                    cout << mem.size() << endl;
                }
            }
            else if(oper == "del") {
                vector<int>::iterator pos;
                pos = find(mem.begin(),mem.end(), mem_size);
                if(pos != mem.end()) {
                    *pos = -1;
                }
                else{
                    cout << "NULL" << endl;
                }
            }
        }
    }
    
    return 0;
}

int judge(string station,string first,string second) {
    int first_pos = (int)station.find(first);
    int second_pos = (int)station.find(second);
    if(first_pos < second_pos)
        return 1;
    else
        return 2;
}


int test_2() {
    string station;
    while(cin >> station) {
        string first;
        cin >> first;
        string second;
        cin >> second;
        int first_pos = station.find(first);
        int second_pos = station.find(second);
        int is_forward = judge(station,first,second);
        reverse(station.begin(), station.end());
        int is_backward = judge(station, first, second);
        
        
        if((is_forward == 1) && (is_backward == 2)) {
            cout << "forward" << endl;
        }
        else if((is_forward == 2) && (is_backward == 1)){
            cout << "backward" << endl;
        }
        else if(((is_forward == 1) && (is_backward == 1)) || ((is_forward == 2) && (is_backward == 2))){
            cout << "both" << endl;
        }
        else {
            cout << "invalid" << endl;
        }
        
        
    }
    return 0;
    
}

