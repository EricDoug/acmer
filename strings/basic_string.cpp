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

/**********************************
 *          进制转换               *
 **********************************/
int Basic_String::hex2decimal() {
    
    string input;
    while(getline(cin, input)){
        
        int str_len = (int)input.length();
        int res = 0;
        for(int i = str_len - 1; i > 1; i--) {
            char cur = input[i];
            //cout << cur << endl;
            if(cur >= 'A' && cur <= 'F'){
                //cout << pow(16, (str_len - i -1))  << endl;
                res += (10 + cur - 'A') * pow(16, (str_len - i -1));
                cout << res << endl;
            }
            else if(cur >= 'a' && cur <= 'f') {
                res += (10 + cur - 'a')* pow(16, (str_len - i -1));
            }
            else {
                res += (cur - '0') * pow(16, (str_len - i - 1));
                cout << cur << endl;
                cout << pow(16, (str_len - i - 1)) << endl;
                cout << (cur - '0') * pow(16, (str_len - i - 1)) << endl;
                cout << res << endl;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}


/**********************************
 *          句子逆序               *
 *********************************/
int Basic_String::reverseSentence() {
    string input;
    while(getline(cin, input)){
        
        int input_len = input.length();
        // 从后往前扫描单词
        int flag = 1;
        int word_end = 0;
        for(int j=input_len - 1; j >0; --j){
            if(input[j] != ' ' && flag == 1){
                word_end = j; // 记录单词的末尾
                flag = 0;
            }
            else if(input[j] == ' ' && flag == 0)
            {
                flag = 1;
                cout << input.substr(j+1, word_end) << ' ';
                word_end = j - 1;
            }
            else
                continue;
        }
        cout << input.substr(0, word_end) << endl;
        cin.ignore();
    }
    
    return 0;
}

/*********************************
 *       识别有效的子网掩码         *
 *********************************/
bool Basic_String::check_mask(string mask) {
    int len = mask.length();
    
    
    int start = 0;
    int mask_pos = 0;
    vector<int> mask_int;
    string mask_str;
    while(mask_pos != string::npos)
    {
        mask_pos = mask.find_first_of('.', (start+1));
        mask_str = mask.substr(start, (mask_pos - start));
        start = mask_pos + 1;
        char *end;
        int mask2int = static_cast<int>(strtol(mask_str.c_str(), &end, 10));
        mask_int.push_back(mask2int);
    }
    
    if(mask_int.size() != 4)
    {
        return false;
    }
    
    if(mask_int[0] == 255)
    {
        if (mask_int[1] == 255)
        {
            if(mask_int[2] == 255)
            {
                if (mask_int[3] == 254 || mask_int[3] == 252 || mask_int[3] == 248 || mask_int[3] == 240 ||
                    mask_int[3] == 224 || mask_int[3] == 192 || mask_int[3] == 128 || mask_int[3] == 0)
                {
                    
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (mask_int[2] == 254 || mask_int[2] == 252 || mask_int[2] == 248 || mask_int[2] == 240 ||
                    mask_int[2] == 224 || mask_int[2] == 192 || mask_int[2] == 128 || mask_int[2] == 0 )
                {
                    if (mask_int[3] == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            if (mask_int[1] == 254 || mask_int[1] == 252 || mask_int[1] == 248 || mask_int[1] == 240 ||
                mask_int[1] == 224 || mask_int[1] == 192 || mask_int[1] == 128 || mask_int[1] == 0)
            {
                if (mask_int[2] == 0 && mask_int[3] == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        
    }
    else
    {
        if (mask_int[0] == 254 || mask_int[0] == 252 || mask_int[0] == 248 || mask_int[0] == 240 ||
            mask_int[0] == 224 || mask_int[0] == 192 || mask_int[0] == 128 || mask_int[0] == 0)
        {
            if (mask_int[3] == 0 && mask_int[2] == 0 && mask_int[1] == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
    
    return false;
}

/**********************************
 *          检测IP是否合法          *
 **********************************/
bool Basic_String::check_ip(string ip)
{
    
    int start = 0;
    int ip_pos = 0;
    while (ip_pos != string::npos)
    {
        ip_pos = ip.find_first_of('.',start);
        if(ip_pos == 0 || ip[ip_pos+1] == '.')
        {
            return false;
        }
        else
        {
            start = ip_pos + 1;
        }
    }
    
    return true;
}

/**********************************
 *        识别有效的IP和掩码         *
 **********************************/
void Basic_String::recognize_ip_mask() {

    string input;
    int result[7] = {0};
    while (cin >> input)
    {
        // 确定波兰号的位置
        
        int dash_pos = input.find_first_of('~', 0);
        int len = input.length();
        string ip = input.substr(0, dash_pos);
        // cout << ip << endl;
        string mask = input.substr((dash_pos+1), (len-dash_pos));
        // cout << mask << endl;
        
        // 对IP与私网IP进行分类
        
        vector<int> ip_int;
        int start = 0;
        int ip_pos = 0;
        while(ip_pos != string::npos)
        {
            ip_pos = ip.find_first_of('.', start);
            string ip_str = ip.substr(start, (ip_pos - start));
            if (ip[start+1] == '.') {
                
            }
            start = ip_pos + 1;
            // string to int
            char* ip_end;
            int ip2int = static_cast<int>(strtol(ip_str.c_str(), &ip_end, 10));
            ip_int.push_back(ip2int);
        }
        
        
        if(check_ip(ip) && (ip_int[0] < 0 || ip_int[1] < 0 || ip_int[2] < 0 || ip_int[3] < 0))
            result[5] += 1;  // 不合法ip
        else if(check_ip(ip) && ip_int[0] >= 1 && ip_int[0] <= 126 && check_mask(mask))
        {
            if(ip_int[0] == 10)
            {
                result[6] += 1; // 私有IP, 10网段
                
            }
            
            
            result[0] += 1; // A类IP
            
        }
        else if(check_ip(ip) && ip_int[0] >= 128 && ip_int[0] <= 191 && check_mask(mask))
        {
            if(ip_int[0] == 172)
            {
                if (ip_int[1] >= 16 && ip_int[1] <=31)
                {
                    result[6] += 1; // 私有IP， 172网段
                }
            }
                
               
           
            result[1] += 1;  // B类IP
        }
        else if(check_ip(ip) && ip_int[0] >= 192 && ip_int[0] <= 223 && check_mask(mask))
        {
            
            if(ip_int[0] == 192)
            {
                
                if (ip_int[1] == 168) {
                    result[6] += 1;  // 私有IP， 192网段
                }
                
            }
        
            result[2] += 1; // C类IP
        }
        else if(check_ip(ip) && ip_int[0] >= 224 && ip_int[0] <= 239 && check_mask(mask))
        {
            result[3] += 1; // D类IP
        }
        else if(check_ip(ip) && ip_int[0] >= 240 && ip_int[0] <= 255 && check_mask(mask))
        {
            result[4] += 1;  // E类ip
        }
        else if(!check_mask(mask) || !check_ip(ip)){
            result[5] += 1;  // 不合法子网掩码
        }
        
        
        for(int i = 0; i < 7;i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        
    }
    
    
    
}

