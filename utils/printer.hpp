//
//  printer.hpp
//  acmer
//
//  Created by 刘晓东 on 16/7/25.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef printer_hpp
#define printer_hpp

#include "pre_func.h"

class Printer{
public:
    Printer();
    ~Printer();
    static void arrays_printer(const char* s)
    {
        for (int i = 0; i < strlen(s); i ++) {
            cout << s[i] << '\t';
        }
        cout << endl;
    }
    template <typename T>
    static void matrix_printer(vector< vector<T>>& matrix, int row, int col)
    {
        int i,j;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                cout << matrix[i][j];
                cout << "\t";
            }
                cout << endl;
        }
    }
    
    static void int_printer(int* a, int size){
        for (int i = 0; i < size; i++) {
            cout << a[i] << "\t";
        }
        cout << endl;
    }

private:
    
};

#endif /* printer_hpp */
