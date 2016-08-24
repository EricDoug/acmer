//
//  deques.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/24.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "deques.hpp"

/************************
 *    提取不重复的整数     *
 ************************/
int getDuplicateNum(){
    
    int input;
    while(cin >> input) {
        deque<int> int_queue;
        int single;
        int num[10] = {0};
        while(input) {
            single = input % 10;
            input = static_cast<int>(input/10);
            if(num[single] == 0){
                int_queue.push_back(single);
                num[single] += 1;
            }
            else
                num[single] += 1;
        }
        
        int result = 0;
        for(deque<int>::iterator iter=int_queue.begin();iter!=int_queue.end();++iter){
            result = *iter + result * 10;
        }
        cout << result << endl;
    }
    
    return 0;
}
