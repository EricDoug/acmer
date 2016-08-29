//
//  code_jam.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/29.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "code_jam.hpp"


int filereader() {
    char inputfile[] = "/Users/EricDoug/Documents/buaa/test/A-small-attempt0.in";
    ifstream fin(inputfile);
    
    char line[1024] = {0};
    
    string s;
    while(fin >> s) {
        // fin.read(line, sizeof(line));
        cout << s << endl;
    }
    
    return 0;
}


int small() {
    int n;
    char filename[] = "/Users/EricDoug/Documents/buaa/test/output.txt";
    ofstream fout(filename, ios::out);
    char inputfile[] = "/Users/EricDoug/Documents/buaa/test/A-small-attempt0.in";
    ifstream fin(inputfile);
    
    
    string line;
    int count = 0;
    while (!fin.eof()) {
        if (count == 0) {
            fin >> n;
            count++;
            
        }
        int left, right;
        for (int i = 0; i < n; i++)
        {
            fin >> left >> right;
            int result;
            if(left == 0 || right == 0)
            {
                result = 0;
            }
            else
            {
                if(left == right)
                    result = left;
                else
                {
                    int diff = left - right;
                    if(diff > 0)
                        result = right + 1;
                    else
                        result = left;
                }
            }
            
            
            fout << "Case #" << (i+1) << ":" << ' ' << result << endl;
            count++;
        }
    }
    
    fin.close();
    fout.close();
    
    return 0;
}


int B_small() {
    
    int n;
    char filename[] = "/Users/EricDoug/Documents/buaa/test/B/output.txt";
    ofstream fout(filename, ios::out);
    char inputfile[] = "/Users/EricDoug/Documents/buaa/test/B/B-small-attempt0.in";
    ifstream fin(inputfile);
    
    
    int count = 0;
    while(!fin.eof())
    {
        
        if(count == 0)
        {
            fin >> n;
            count++;
        }
        else if(count <= (int)n)
        {
            int A, B, N, K;
            int result = 0;
            fin >> A >> B >> N >> K;
            for(int i = 1; i <= N; i++)
            {
                for(int j = 1; j <= N; j++)
                {
                    if((int)(pow(i, A) + pow(j, B)) % K == 0)
                        result += 1;
                }
            }
            fout << "Case #" << count << ":" << " " << result << endl;
            count++;
            
        }
    }
    
    
    return 0;
}
