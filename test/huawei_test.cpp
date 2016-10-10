//
//  huawei_test.cpp
//  acmer
//
//  Created by EricDoug on 16/10/10.
//  Copyright © 2016年 EricDoug. All rights reserved.
//

#include "huawei_test.hpp"

int reverseKth_test() {
    int k,num;
    while (cin >> num >> k) {
        ListNode *rawHead = create(num);
        
        ListNode *q,*h,*s,*head;
        head = new ListNode(-1);
        h = head;
        int n = num/k;
        for(int i = 0; i < n; i++) {
            q = rawHead;                   // 保存原头结点
            for (int j = 1; j < k; j++) {
                rawHead = rawHead->next;    // 遍历到原尾结点
            }
            head->next=rawHead;     // 原来的尾结点变成了新的头结点
            head=q;                    // 原来的首结点接下一个组内的新的首结点(旧的尾结点)
            rawHead = reverseKthList(q, k); // 逆置链表，返回下一个结点
        }
        
        head->next = rawHead;
        h = h->next;
        while (h->next) {
            cout << h->val << "->";
            s = h;
            h = h->next;
            delete s;
        }
        cout << h->val << endl;
        delete h;
    }
    
    return 0;
}
