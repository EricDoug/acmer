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
    
    // 确定字符互异
    bool checkDifferent(string initString);
    
    // 进制转换
    int hex2decimal();
    
    // 句子逆序
    int reverseSentence();
    
    // 识别有效的IP地址，并进行分类统计
    void recognize_ip_mask();
    
    // 检测子网掩码是否合法
    bool check_mask(string mask);
    
    // 检测ip是否合法
    bool check_ip(string ip);
    
};



#endif /* basic_string_hpp */
