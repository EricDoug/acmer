//
//  ip_masks.cpp
//  acmer
//
//  Created by EricDoug on 16/9/11.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "ip_masks.h"
#include <sstream>

/*********************
 * @func:判断ip是否属于同一子网
 * @return: 0: ip1与ip2属于同一子网
 1: ip或者子网掩码格式非法
 2: ip1与ip2不属于同一子网
 *********************/
int check_ip_network() {
    
    string input;
    char dot;
    stringstream ss;
    while (cin >> input) {
        int mask1 = 0, mask2 = 0, mask3 = 0, mask4 = 0;
        int ip1a = 0, ip1b = 0, ip1c = 0, ip1d = 0;
        int ip2a = 0, ip2b = 0, ip2c = 0, ip2d = 0;
        // 处理子网掩码
        ss << input;
        ss >> mask1 >> dot >> mask2 >> dot >> mask3 >> dot >> mask4;
        ss.clear();
        
        // 处理ip1
        cin >> input;
        ss << input;
        ss >> ip1a >> dot >> ip1b >> dot >> ip1c >> dot >> ip1d;
        ss.clear();
        
        // 处理ip2
        cin >> input;
        ss << input;
        ss >> ip2a >> dot >> ip2b >> dot >> ip2c >> dot >> ip2d;
        ss.clear();
        
        if((mask1>255 || mask1 < 0) || (mask2 > 255 || mask2 <0) || (mask3 > 255 || mask3 < 0) || (mask4 > 255 || mask4 < 0) ||
           (ip1a > 255 || ip1a < 0) || (ip1b > 255 ||ip1b < 0) || (ip1c > 255 || ip1c < 0) || (ip1d > 255 || ip1d < 0) ||
           (ip2a > 255 || ip2a < 0) || (ip2b > 255 || ip2b < 0) || (ip2c > 255 || ip2c < 0) || (ip2d > 255 || ip2d < 0))
            cout << 1 << endl;
        else if(((mask1&ip1a) == (mask1&ip2a)) && ((mask2&ip1b) == (mask2&ip2b)) && ((mask3&ip1c)==(mask3&ip2c)) && ((mask4&ip1d)==(mask4&ip2d)))
            cout << 0 << endl;
        else
            cout << 2 << endl;
        
        
    }
    
    
    
    return 0;
    
    
}
