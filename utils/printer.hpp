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
    void arrays_printer(const char* s);
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

private:
    
};

#endif /* printer_hpp */
