//
//  linked_list.hpp
//  acmer
//
//  Created by 刘晓东 on 16/8/22.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include "pre_func.h"
#include <stack>


// 定义单链表结点
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Linked_List {
private:
    Linked_List();
    ~Linked_List();
    
public:
    // 从尾到头打印链表
    vector<int> printListFromTailToHead(struct ListNode* head);
    
    // 使用递归从尾到头打印链表
    vector<int> printListFromT2H_recur(struct ListNode* head);
};

#endif /* linked_list_hpp */
