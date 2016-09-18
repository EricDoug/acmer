//
//  basic_math.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/23.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "basic_math.hpp"

bool isPrime(long x) {
    for (long i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int factor_count(int n) {
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }
    
    return count;
}
/***********************************
 *        小球落地所走路程            *
 ***********************************/
double getJourney(int high,int k){
    double res = high;
    for(int i=1;i<k;i++){
        res += (high/(pow(2.0,i-1)));
    }
    return res;
}


double getKthHigh(int high,int k){
    return high/(pow(2.0,k));
}


/*************************************
 *              素数伴侣              *
 *************************************/
int prime_company() {
    int n;
    while(cin >> n) {
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        int max_prime = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPrime(arr[j]+arr[i]))
                    max_prime++;
            }
        }
        cout << max_prime << endl;
    }
    return 0;
}


/***********************************
 *           水仙花数               *
 **********************************/
bool is_shuixian(int x){
    int a = x;
    int sum = 0;
    while(a){
        a %= 10;
        sum += (a*a*a);
        a /= 10;
    }
    if(sum == x)
        return true;
    else
        return false;
}
int shuixian_test() {
    int m,n;
    while(cin >> m >> n)
    {
        bool flag = false;
        for(int i=m;i<=n;i++){
            if(is_shuixian(i)){
                cout << i << ' ';
                flag = true;
            }
        }
        if(flag)
            cout << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

