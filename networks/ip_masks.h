//
//  ip_masks.h
//  acmer
//
//  Created by EricDoug on 16/9/11.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#ifndef __acmer__ip_masks__
#define __acmer__ip_masks__

#include "pre_func.h"
/*********************
 * @func:判断ip是否属于同一子网
 * @return: 0: ip1与ip2属于同一子网
            1: ip或者子网掩码格式非法
            2: ip1与ip2不属于同一子网
 *********************/
int check_ip_network();

#endif /* defined(__acmer__ip_masks__) */
