
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
    int mod = 0;
    int sum = 0;
    while(a){
        mod = a % 10;
        sum += (mod*mod*mod);
        a = a/10;
        
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


/*********************************
 *            前n项和             *
 *********************************/
int sum_n_sqrt(){
    int n,m;
    while(cin >> n >> m) {
        float sum = n;
        float x = n;
      	 for(int i = 1;i < m;i++){
             x = sqrt(x);
             sum += x;
         }
        cout << setiosflags(ios::fixed) <<  setprecision(2) <<  sum << endl;
    }
    return 0;
}

/**********************************
 *            称砝码               *
 **********************************/
int weight_chen(){
    int n;
    while(cin >> n){
        vector<int> m(n,0);
        vector<int> x(n,0);
        for(int i=0;i<n;i++){
            cin >> m[i];
        }
        for(int i = 0; i < n;i++){
            cin >> x[i];
        }
        vector<int> weight;
        for(int i=0;i<=x[0];i++){
            int w = m[0]*i;
            weight.push_back(w);
        }
        
        for(int i=1;i<n;i++){
            int len = weight.size();
            for(int j=1;j<=x[i];j++){
                
                for(int k=0;k<len;k++){
                    int w = weight[k] + j*m[i];
                   	if(find(weight.begin(),weight.end(),w) == weight.end())
                        weight.push_back(w);
                }
            }
        }
        cout << weight.size() << endl;
        
    }
    
    return 0;
}


 
