//
//  first_appear.hpp
//  acmer
//
//  Created by 刘晓东 on 16/8/4.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef first_appear_hpp
#define first_appear_hpp

#include"pre_func.h"

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        chars.push_back(ch);
        word_bag[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i < chars.size();i++){
            if(word_bag[chars[i]] == 1)
            {
                return chars[i];
            }
        }
        return '#';
    }
private:
    
    vector<char> chars;
    map<char,int> word_bag;
    
};

#endif /* first_appear_hpp */
