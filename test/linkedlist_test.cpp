//
//  linkedlist_test.cpp
//  acmer
//
//  Created by 刘晓东 on 16/8/25.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "linkedlist_test.hpp"


void deleteDuplicate2_test() {
    ListNode* pHead = NULL;
    int data[] = {1,1,1,1,2,2};
    int data_size = sizeof(data)/ sizeof(int);
    for(int i = data_size-1; i >= 0; i--) {
        ListNode* p = new ListNode(data[i]);
        p->next = pHead->next;
        pHead->next = p;
    }
    
    Linked_List* linked_list = new Linked_List;
    ListNode* deleteDupList = NULL;
    deleteDupList = linked_list->deleteDuplicateNode2(pHead);
    
    
}