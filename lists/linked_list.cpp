//
//  linked_list.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/22.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "linked_list.hpp"


/*****************************
 *    使用栈打印从头到尾的链表   *
 *****************************/
vector<int> Linked_List::printListFromTailToHead(struct ListNode *head){
    
    stack<ListNode*> listStack;
    
    struct ListNode *pNode = head;
    vector<int> results;
    
    // 将链表压栈
    while (pNode != NULL) {
        
        listStack.push(pNode);
        pNode = pNode->next;
    }
    // 从栈中取出元素
    while (!listStack.empty()) {
        pNode = listStack.top(); // 取出栈顶元素
        results.push_back(pNode->val);
        listStack.pop();
    }
    
    return results;
}

/***********************************
 *     使用递归打印从头到尾的链表      *
 ***********************************/
vector<int> Linked_List::printListFromT2H_recur(struct ListNode *head){
    vector<int> results;
    
    if (head != NULL) {
        if (head->next != NULL) {
            printListFromT2H_recur(head->next);
        }
        results.push_back(head->val);
    }
    
    return results;
    
}