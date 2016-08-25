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
//private:
//    Linked_List();
//    ~Linked_List();
    
public:
    // 从尾到头打印链表
    vector<int> printListFromTailToHead(struct ListNode* head);
    
    // 使用递归从尾到头打印链表
    vector<int> printListFromT2H_recur(struct ListNode* head);
    
    // 反转链表
    ListNode* reverseList(ListNode* pHead);
    
    // 合并两个排序的链表
    ListNode* merge(ListNode* pHead1, ListNode* pHead2);
    ListNode* merge2(ListNode* pHead1, ListNode* pHead2);  // 使用非递归
    
    // 计算链表长度
    int length(ListNode* pHead);
    
    // 删除重复元素
    ListNode* deleteDuplicateNode(ListNode* pHead);
    
    // 删除链表中所有的重复的结点
    ListNode* deleteDuplicateNode2(ListNode* pHead);
    
};

#endif /* linked_list_hpp */
