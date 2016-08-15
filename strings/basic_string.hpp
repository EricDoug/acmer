//
//  basic_string.hpp
//  acmer
//
//  Created by 刘晓东 on 16/8/2.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef basic_string_hpp
#define basic_string_hpp

#include "pre_func.h"

class Basic_String {
private:
    
public:
    // 字符串倒转
    void reverseString(char* s, int from, int to);
    
    // 字符串循环左移
    void leftRotateString(char* s, int n, int m);
    
    // 字符交换
    //void swap(char* s1, char* s2);
    
    // 字符串或者数组全排列
    void permutation(int* a, int size, int n);
    
    // 替换空格
    void replaceSpace(char* str, int length);
    
    // 正则匹配
    bool regMatch(const char* str, const char* pattern);
    
    // 判断字符串是否是数字
    bool isDigit(char x);
    
    // 判断字符串是否是数值
    bool isNumeric(char* string);
};

#endif /* basic_string_hpp */
