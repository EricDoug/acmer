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