//
//  multi_threads_test.hpp
//  acmer
//
//  Created by 刘晓东 on 16/8/16.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef multi_threads_test_hpp
#define multi_threads_test_hpp

#include "multi_threads.hpp"

//void multi_threads_test1(void* args){
//    pthread_t tids[NUM_THREADS];
//    
//    for (int i = 0; i < NUM_THREADS; ++i) {
//        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);  // 参数:创建的线程id， 线程参数， 线程运行函数的起始地址， 运行函数的参数
//        
//        if(ret != 0)  // 创建线程成功返回0
//        {
//            cout << "pthread_create error:error_code=" << ret << endl;
//        }
//    }
//    
//    pthread_exit(NULL);
//}

#endif /* multi_threads_test_hpp */
