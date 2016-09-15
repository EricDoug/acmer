//
//  tencent.cpp
//  acmer
//
//  Created by EricDoug on 16/9/11.
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "tencent.h"


int rank_array(int* a, int len) {
    
    int temp;
    for(int i = len-1; i >= 0; i--) {
        temp = a[i];
    }
    return 0;
}

int f(int a, int b, int c){
    return 0;
    
}


class X {
public:
    void xoo() {}
};

int x =4;

void incre() {
    static int x = 1;
    x *= x+1;
    
    printf("%d",x);
}
//
//int count = 0;
//
//int f(int n) {
//
//    count++;
//
//    if(n <= 3)
//        return 1;
//    else
//        return f(n-2) + f(n-6) + 1;
//}

//class Base{
//public:
//    virtual ~Base() {
//        cout << "Base Destructor" << endl;
//    }
//
//
//};
//
//class Derived:public Base {
//public:
//    ~Derived(){
//        cout << "Deric destrucor" << endl;
//    }
//};

bool is_prime(int x) {
    
    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int tencent_1() {
    int n;
    while (cin >> n) {
        int count = 0;
        for(int i=2;i <= n/2; i++)
            if(is_prime(i) && is_prime(n-i))
                count++;
        cout <<  count << endl;
    }
    
    return 0;
}

void test(){

    //    const int N= 10;
    //    const int M = 2;
    //    int* a = new int[N];
    //    for (int i = 0; i < N; i++) {
    //        a[i] = (0== i%2)?  (i+2):(i+0);
    //    }
    //
    //    int (*b)[N/M] = (int (*)[N/M])a;
    //    for(int i = 0;i < M;++i)
    //        for(int j = 0;j < N/M;++j)
    //            printf("%d",b[i][j]);
    //cout << sizeof(X) << endl;
    
    
    //    int i;
    //    for (i= 1; i < x; i++) {
    //        incre();
    //    }
    
    //    f(f(9));
    //
    //    cout << count << endl;
    
    //    Base* p = new Derived();
    //    delete p;
    
    //    char *p[] = {"TENCENT","CAMPUS","RECUITING"};
    //    char **pp[] = {p+2, p+1, p};
    //    char ***ppp = pp;
    //    
    //    printf("%s", **++ppp);
    //    printf("%s", *++*++ppp);
}


