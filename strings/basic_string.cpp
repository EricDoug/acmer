//
//  basic_string.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/2.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "basic_string.hpp"
#include "printer.hpp"
/*************************
 *       字符交换         *
 *************************/
//void Basic_String::swap(char* s1, char* s2)
//{
//    char tmp;
//    tmp = *s1;
//    *s1 = *s2;
//    *s2 = tmp;
//}


/*************************
 *       字符串转置        *
 *************************/
void Basic_String::reverseString(char* s, int from, int to)
{
    while (from < to)
    {
        swap(s[from++], s[to--]);
//        from++;
//        to--;
//        char t = s[from];
//        s[from++] = s[to];
//        s[to--] = t;
    }
}

/**************************
 *     字符串循环左移       *
 *************************/
void Basic_String::leftRotateString(char *s, int n, int m)
{
    m %= n;
    reverseString(s, 0, m - 1);
    reverseString(s, m, n - 1);
    reverseString(s, 0, n - 1);
    
}


/*****************************
 *   字符串或者数组全排列        *
 *****************************/
void Basic_String::permutation(int *a, int size, int n)
{
    if (n == size - 1 ) {
        Printer::int_printer(a, size);
        return;
    }
    
    for (int i = n; i < size; i++) {
        swap(a[i], a[n]);
        permutation(a, size, n+1);
        swap(a[i], a[n]);
    }
}


/*****************************
 *           空格替换         *
 *****************************/
void Basic_String::replaceSpace(char *str, int length)
{
    
    bool is_char = true;
    int space_num = 0;
    cout << str << endl;
    
    // 计算空格数目
    for(int i = 0; i < length; i++)
    {
        if(str[i] != ' ')
        {
            //is_char = true;
            continue;
        }
        else
        {
            //if(is_char)
            //{
                space_num++;
                is_char = false;
                continue;
            //}
        }
    }
    
    // 替换
    for(int j=length-1;j>0; j--)
    {
        if(str[j] != ' ')
        {
            is_char = true;
            cout << j+2*space_num << endl;
            str[j+2*space_num] = str[j];
            continue;
        }
        else
        {
            //if(is_char)
           // {
                str[j+2*space_num] = '0';
                str[j+2*space_num - 1] = '2';
                str[j+2*space_num -2] = '%';
                //is_char = false;
                space_num--;
                continue;
            //}
        }
    }
    
}


/*******************************
 *         正则匹配             *
 *******************************/
bool Basic_String::regMatch(const char *str, const char *pattern) {
    
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }
    
    if (*str != '\0' && *pattern == '\0') {
        return false;
    }
    
    if (*(pattern+1) == '*') {
        if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
            return regMatch(str, pattern+2) || regMatch(str+1, pattern+2) || regMatch(str+1, pattern);
        }
        else
            return regMatch(str, pattern+2);
    }
    
    if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
        return regMatch(str+1, pattern+1);
    }
    
    return false;
}


/*******************************
 *     判断字符是否是数字         *
 *******************************/
bool Basic_String::isDigit(char x){
    
    if (x >= '0' && x <= '9') {
        return true;
    }
    else
        return false;
}

/******************************
 *     判断字符串是否是数值      *
 *****************************/

bool Basic_String::isNumeric(char *str){
    
    if (str == NULL) {
        return false;
    }
    
    int index = 0;
    
    // 判断正负号
    if (str[index] == '+' || str[index] == '-') {
        str++;
    }
    
    if (str[index] == '\0') {
        return false;
    }
    
    // 扫描数字
    while(isDigit(str[index])) {
        index++;
    }
    
    // 判断是科学计数法还是小数
    if (str[index] != '\0') {
        // 若是小数
        if (str[index] == '.') {
            index++;
            while (isDigit(str[index])) {
                index++;
            }
            if (str[index] == 'e' || str[index] == 'E') {
                // 正负判断
                index++;
                if (str[index] == '+' || str[index] == '-') {
                    index ++;
                }
                if (str[index] == '\0') {
                    return false;
                }
                
                while(isDigit(str[index])) {
                    index++;
                }
                
                return str[index] == '\0' ? true:false;
            }
        }
        // 若是科学数
        else if(str[index] == 'e' || str[index] == 'E'){
            index++;
            // 正负判断
            if (str[index] == '+' || str[index] == '-') {
                index++;
            }
            if (str[index] == '\0') {
                return false;
            }
            
            while(isDigit(str[index])) {
                index++;
            }
            return str[index] == '\0' ? true:false;
        }
    }
    
    return str[index] == '\0' ? true:false;
}

/********************************
 *         确定字符互异           *
 ********************************/
bool Basic_String::checkDifferent(string initString){
    
    int strLen = (int)initString.size();
    
    int isDuplicate = 0;
    for (int i = 0; i < strLen; i++) {
        
        int val = initString[i] - 'a';
        if((isDuplicate & (1 << val)) > 0){
            return false;
        }
        
        isDuplicate |= (1 << val);
    }
    return true;
    
}



