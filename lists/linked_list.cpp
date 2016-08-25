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

/*******************************
 *          反转链表            *
 *******************************/
ListNode* Linked_List::reverseList(ListNode* pHead){
    
    ListNode* reverseList_head = NULL;
    ListNode* pCur = pHead;
    ListNode* pPre = NULL;
    while (pCur != NULL) {
        ListNode* pNext = pCur->next;
        if (pNext == NULL) {
            reverseList_head = pCur;
        }
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    return reverseList_head;
}

/***************************
 *    合并两个排序的链表      *
 **************************/
ListNode* Linked_List::merge(ListNode* pHead1,ListNode* pHead2) {
    // merge后的链表
    ListNode* pMerge = NULL;
    if (pHead1 == NULL) {
        return pHead2;
    }else if(pHead2 == NULL)
        return pHead1;
    
    // 选择较小的加入到合并的链表
    if (pHead1->val < pHead2->val) {
        pMerge = pHead1;
        
        pMerge->next = merge(pHead1->next, pHead2);
    }
    else {
        pMerge = pHead2;
        pMerge->next = merge(pHead2->next, pHead1);
    }
    
    return pMerge;
}

/**************************
 *       计算链表长度       *
 **************************/
int Linked_List::length(ListNode* pHead) {
    
    unsigned int len = 0;
    ListNode* pNode = pHead;
    while (pHead != NULL) {
        ++len;
        pNode = pNode->next;
    }
    
    return len;
}


/******************************
 *   合并两个排序的链表(非递归)   *
 ******************************/
ListNode* Linked_List::merge2(ListNode* pHead1,ListNode* pHead2) {
    
    if (pHead1 == NULL) {
        return pHead2;
    }
    else if(pHead2 == NULL) {
        return pHead1;
    }
    
    int p1_len = length(pHead1);
    int p2_len = length(pHead2);
    
    int p_diff = p1_len - p2_len;
    ListNode* pLong = pHead1;
    ListNode* pShort = pHead2;
    
    if (p1_len < p2_len) {
        p_diff = p2_len - p1_len;
        pLong = pHead2;
        pShort = pHead1;
    }
    
    for (int i=0; i < p_diff; i++) {
        pLong = pLong->next;
    }
    while ((pLong != NULL) && (pShort != NULL)) {
        if (pLong->val == pShort->val ) {
            return pLong;
        }
        pLong = pLong->next;
        pShort = pShort->next;
    }
    
    return NULL;
}

/*******************************
 *        排序链表中去重         *
 ******************************/
ListNode* Linked_List::deleteDuplicateNode(ListNode *pHead) {

    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }
    
    ListNode* pPre = pHead;
    ListNode* pCur = pHead;
    
    while (pPre != NULL) {
        pCur = pPre->next;
        if (pCur && (pCur->val == pPre->val)) {
            pPre->next = pCur->next;
            delete pCur;
        }
        else {
            pPre = pCur;
        }
    }
    
    return pHead;
}


/********************************
 *    删除链表中所有的重复的结点    *
 *******************************/
ListNode* Linked_List::deleteDuplicateNode2(ListNode* pHead) {
    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }
    
    ListNode* pPre = pHead;
    ListNode* pCur = pPre->next;
    ListNode* pNext;
    bool bDup;
    while (pCur) {
        pNext = pCur->next;
        bDup = false;
        while (pNext && (pCur->val == pNext->val)) {
            pPre->next = pNext;
            delete pCur;
            pCur = pNext;
            pNext = pCur->next;
            bDup = true;
        }
        if (bDup) {
            pPre->next = pNext;
            delete pCur;
        }
        else {
            pPre = pCur;
        }
        
        pCur = pNext;
    }
    
    return pHead;
    
    
}


