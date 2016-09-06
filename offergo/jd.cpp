//
//  jd.cpp
//  acmer
//
//  Created by 刘晓东 on 16/9/6.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "jd.hpp"

int test_a() {
    
    int m;
    int n;
    while(cin >> n)
    {
        double sum = 0.0;
        cin >> m;
        for(int i=0; i < m; i++) {
            sum += n;
            n = (double)sqrt((double)n);
            cout.unsetf(ios::fixed);
            cout << n << endl;
        }
        cout << sum << endl;
    }
    return 0;
}

int test_b() {
    int n,m;
    while(cin >> n >> m) {
        vector<int> record(n,-1);
        
        for(int i = 0; i < m; i++) {
            int k,v;
            cin >> k >> v;
            record[k-1] = v;
        }
        int flag = 1;
        for(int i = 1; i < n-1; i++) {
            if(abs(record[i] - record[i-1]) > 1 || abs(record[i+1] - record[i]) > 1){
                cout << "IMPOSSIBLE" << endl;
                flag = 0;
            }
        }
        int max_margin = 0;
        if(flag){
            for(int i = 0; i < n; i++){
                if(record[i] == 0){
                    for(int j = i+1; j < n; j++){
                        if(record[j] == 0){
                            max_margin = max(max_margin, (j-i-1));
                        }
                    }
                }
            }
            
            cout << (max_margin/2) << endl;
        }
    }
    
    return 0;
}

struct Circle {
    int x;
    int y;
    int r;
    Circle(int x_val, int y_val, int r_val) : x(x_val), y(y_val), r(r_val){}
};


int test_c() {
    
    int x,y,r;
    while(cin >> x >> y >> r){
        Circle *c1 = new Circle(x,y,r);
        cin >> x >> y >> r;
        Circle *c2 = new Circle(x,y,r);
        cin >> x >> y >> r;
        Circle *c3 = new Circle(x,y,r);
        
        int c12_mid_x = c1->x + c2->x;
        int c12_mid_y = c1->y + c2-> y;
        
        if(c12_mid_x == c3->x) {
            cout << c12_mid_x << ' ' << c12_mid_y << endl;
        }
        
    }
    
    return 0;
}

