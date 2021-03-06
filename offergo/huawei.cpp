//
//  huawei.cpp
//  acmer
//
//  Created by EricDoug on 16/9/118
//  Copyright (c) 2016年 EricDoug. All rights reserved.
//

#include "huawei.h"

// 学英语
string num_egword(int x){
    switch(x){
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
    
    return "error";
}

string num_cell(int x){
    switch (xueyingyu()) {
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 30: return "thirty";
        case 40: return "forty";
        case 50: return "fifty";
        case 60: return "sixty";
        case 70: return "seventy";
        case 80: return "eighty";
        case 90: return "ninety";
        case 100: return "hundred";
        case 1000: return "thousand";
    }
    
    return "error";
}



int xueyingyu(){
    long x;
    while (cin >> x) {
        if(x <= 0){
            cout << "error" << endl;
            return 1;
        }
        cout << x;
        stack<int> num_bag;
        int tmp = x;
        int a = 0;
        while(tmp){
            a = tmp/10;
            num_bag.push(a);
            tmp /= 10;
        }
        int len = num_bag.size();
        while(!num_bag.empty()){
            int num;
            if(len <= 1){
                num = num_bag.top();
                num_bag.top();
                cout << num_egword(x) << endl;
                len--;
            }
            if (len <= 2) {
                
            }
        }
        
        
    }
    
    return 0;
}

// 迷宫问题
int maze_dfs() {
    int m,n;
    while(cin >> m >> n){
        vector<vector<int>> map(m, vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        Node* startNode = new Node(0,0);
        Node* endNode = new Node(m-1,n-1);
        
        stack<Node*> s;
        s.push(startNode);
        visited[startNode->x][startNode->y] = 1;
        int step[][2] = {{1,0}, {0,1}};
        while (!s.empty())
        {
            bool flag = false;
            Node* curNode = s.top(); // 取当前节点
            if(curNode->x == endNode->x && curNode->y == endNode->y)
            {
                break;  // 如果到出口了，退出
            }
            else
            {
                for(int i=0;i<2;i++)
                {
                    Node* nextNode = new Node(curNode->x+step[i][0], curNode->y+step[i][1]);
                    if(nextNode->x >=0 && nextNode->x < m && nextNode->y >= 0 && nextNode->y <n
                       && map[nextNode->x][nextNode->y] == 0 && visited[nextNode->x][nextNode->y] == 0)
                    {
                        s.push(nextNode);
                        visited[nextNode->x][nextNode->y] = 1;
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    continue;
            }
           
            s.pop();
            
        }
        stack<Node*> reverseS;
        while (!s.empty()) {
            Node* curNode = s.top();
            reverseS.push(curNode);
            s.pop();
        }
        
        while (!reverseS.empty()) {
            Node* curNode = reverseS.top();
            cout << "(" << curNode->x << "," << curNode->y << ")" << endl;
            reverseS.pop();
        }
        
        
    }
    
    return 0;
}

// 名字漂亮度
int pretty_name() {
    
    int N;
    while(cin >> N){
        for(int i=0;i<N;i++){
            string str;
            cin >> str;
            int len = str.length();
            int char_map[26] = {0};
            for(int j = 0;j < len;j++){
                if(str[j] >= 'a' && str[j] <= 'z'){
                    char_map[str[j] - 'a']++;
                }
                else {
                    char_map[str[j] - 'A']++;
                }
            }
            sort(char_map,char_map+26);
            int sum = 0;
            int init = 26;
            for(int j = 25;j>=0;j--){
                sum += (char_map[j]*init);
                init--;
            }
            cout << sum << endl;
            
        }
    }
    
    return 0;

}


// 输出单向链表中倒数第k个结点
int outputkthNode(){
    int n;
    while(cin >> n){
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            ListNode* pNode = new ListNode(value);
            cur->next = pNode;
            cur=pNode;
        }
        int k;
        cin >> k;
        if(k <= 0){
            cout << 0 << endl;
            continue;
        }
        ListNode* faster = head->next;
        ListNode* slower = head->next;
        // faster先走k步
        for(int j=0;j<k;j++)
            faster=faster->next;
        
        while(faster != NULL){
            slower = slower->next;
            faster = faster->next;
        }
        cout << slower->val << endl;
        
    }
    
    
    return 0;
}

// 创建单链表
ListNode* create(int num){
    ListNode *head=NULL, *pNode, *pCur=NULL;
    for(int i=1;i <= num;i++){
        pNode = new ListNode(i);
        if(head == NULL){
            head = pNode;
        }
        else {
            pCur->next = pNode;
        }
        pCur = pNode;
    }
    return head;
}

// 打印链表
void printList(ListNode* head){
    ListNode* pNode = head;
    while (pNode != NULL) {
        cout << pNode->val << ' ';
        pNode = pNode->next;
    }
    cout << endl;
    delete pNode;
}

// 链表逆序
ListNode* reverseList(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *pCur=head, *pNext=NULL, *pPre=NULL, *pReverseHead=NULL;
    while (pCur != NULL) {
        pNext = pCur->next;
        if (pNext == NULL) {
            pReverseHead = pCur;
        }
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    
    return pReverseHead;
}

// 逆序k个
ListNode* reverseKthList(ListNode* head,int k){
    if (head == NULL) {
        return NULL;
    }
    
    ListNode *pCur=head, *pPre=NULL, *pNext=NULL;
    for (int i=0; i < k; i++) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    return pCur;
    
}

// 链表相邻元素翻转
int reverse_adj_list(){
    int m;
    while(cin >> m){
        ListNode *head,*h,*s,*p,*q,*l;
        p = create(m);
        head = new ListNode(-1);
        h = head;
        printList(p);
        while (p != NULL && p->next != NULL) {
            q = p;
            p = p->next;
            head->next = p;
            l = p->next;
            p->next = q;
            head = q;
            p=l;
        }
        head->next = p;
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

// 去掉字符串中大写字母、小写字母和数字字符
int duplicate_some() {
    string str;
    while(cin >> str){
        string new_str;
        for(int i = 0;i<str.size();i++){
            if(isalnum(str[i]))
                new_str.push_back(str[i]);
        }
        cout << new_str << endl;
    }
    
    return 0;
}

// 字符统计
string int2string(int m){
    string tmp;
    while(m>0){
        tmp.push_back(m%10 + '0');
        m /= 10;
    }
    int len = tmp.size();
    char t;
    for(int i=0;i<len/2;i++){
        t = tmp[i];
        tmp[i] = tmp[len-1-i];
        tmp[len-1-i] = t;
    }
    return tmp;
}

int character_stat() {
    string str;
    while(cin >> str){
        int len = str.length();
        int count = 1;
        string new_str;
        for(int i=0;i<len;i++)
        {
            if(str[i] == str[i+1])
            {
                count++;
            }
            else
            {
                new_str.push_back(str[i]);
                if(count > 1)
                {
                    string num = int2string(count);
                    new_str += num;
                    count = 1;
                }
            }
        }
        if(count > 1)
        {
            new_str.push_back(str[len-1]);
            string num = int2string(count);
            new_str += num;
        }
        
        cout << new_str << endl;
    }
    
    return 0;
}

// 字符转换
int stringChange(){
    char input[100];
    while (cin.getline(input, 100))
    {
        int len = strlen(input);
        char output[100];
        int n=0;
        for (int i=0; i < len; i++)
        {
            if(isalpha(input[i])){
                if(input[i] == 'z')
                    output[n++] = 'a';
                else if(input[i] == 'Z')
                    output[n++] = 'A';
                else
                    output[n++] = input[i] + 1;
            }
            else
                output[n++] = input[i];
        }
        output[n] = '\0';
        cout << output << endl;
    }
    
    return 0;
}

// 字符串乘积
int mul(){
    char input1[100],input2[100],output[100];
    while(cin >> input1 >> input2) {
        int m = strlen(input1);
        int n = strlen(input2);
        
        long long x = 0;
        for(int i=0;i < m;i++){
            x += (input1[i] - '0') * pow(10.0, --m);
        }
        long long y = 0;
        for (int j = 0; j < n; j++) {
            y += (input2[j] - '0')* pow(10.0, --n);
        }
        
        long long mul_res = x*y;
        string res;
        if(mul_res == 0){
            res.push_back('0');
            cout << res << endl;
            return 0;
        }
        stack<char> st;
        while(mul_res > 0)
        {
            char ch = mul_res%10 + '0';
            st.push(ch);
            mul_res /= 10;
        }
        while (!st.empty())
        {
            char ch = st.top();
            res.push_back(ch);
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}

// 升序比较
int cmp_asec(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int cmp_desc(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

// 奇偶排序
int sort_jiou(){
    int n;
    while(cin >> n)
    {
        int ji_num = 0,ou_num = 0;
        int* ji = new int[n];
        int* ou = new int[n];
        int* num = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            if(num[i]%2 == 1)
            {
                ji[ji_num++] = num[i];
            }
            else
            {
                ou[ou_num++] = num[i];
            }
        }
        // 奇数升序
        qsort(ji, ji_num, sizeof(int), cmp_asec);
        // 偶数降序
        qsort(ou, ou_num, sizeof(int), cmp_desc);
        
        int m = 0;
        for (int i = 0; i < ji_num && i < ou_num; i++)
        {
            num[m++] = ji[i];
            num[m++] = ou[i];
        }
        if (ji_num > ou_num)
        {
            for (int j=ou_num; j < ji_num; j++)
            {
                num[m++] = ji[j];
            }
        }
        else
        {
            for(int j = ji_num; j < ou_num; j++){
                num[m++] = ou[j];
            }
        }
        
        for(int k=0;k<m;k++)
            cout << num[k] << " ";
        
        delete[] num;
        delete[] ji;
        delete[] ou;
        
    }
    
    return 0;
}
