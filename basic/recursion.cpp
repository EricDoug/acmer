//
//  recursion.cpp
//  acmer
//
//  Created by EricDoug on 16/7/31.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "recursion.h"

/********************************
 *             倒数              *
 ********************************/
double Recursion::reciprocal(double a)
{
    double x = 1;
    
    while (a * x >= 2)
    {
        if (a > 1)
            x /= 10;
        else
            x *= 10;
        
        
    }
    double t = a;
    while (fabs(x-t) > 1e-6)
    {
        t = x;
        x = x * (2 - a * x);
    }
    return x;
}


/********************************
 *           平方根              *
 ********************************/
double Recursion::mysqrt(double a)
{
    if (a < 1e-6) {
        return 0;
    }
    
    double x = 1;
    while (a * x * x >= 3)
    {
        x *= 0.1;
    }
    double t = a;
    while (fabs(x - t) > 1e-6)
    {
        t = x;
        x = (3 - a * t * t) * t/2;
    }
    
    return reciprocal(x);
}