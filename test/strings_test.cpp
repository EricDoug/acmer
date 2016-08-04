//
//  strings_test.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/2.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "strings_test.hpp"


int left_rotate_test() {
    
    char input[] = {'a','b','c','d','e','f','\0'};
    
    Basic_String* basic_string = new Basic_String;
    
    cout << input << endl;
    
    basic_string->leftRotateString(input, 6, 3);
    
    cout << input << endl;
    
    
    return 0;
}


int permutation_test(){

    int a[] = {1, 2, 3, 4};
    Basic_String* basic_string = new Basic_String;
    basic_string->permutation(a, sizeof(a)/sizeof(int), 0);
    return 0;
}

int spaceReplace_test(){
    
    char *str = " helloworld";
    cout << str << endl;
    cout << strlen(str) << endl;
    int length = strlen(str) / sizeof(char);
    
    Basic_String* basic_string = new Basic_String;
    basic_string->replaceSpace(str, length);
    return 0;
}