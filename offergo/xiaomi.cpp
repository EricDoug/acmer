//
//  xiaomi.cpp
//  
//
//  Created by EricDoug on 16/9/26.
//
//
#include "xiaomi.h"


int xiaomi_1(){
    
    int n;
    while(cin >> n){
        TNode* root = new TNode(0);
        TNode* pNode = root;
        for(int i=0;i<n;i++){
            int parent,node;
            cin >> parent >> node;
            if (pNode->value == parent) {
                TNode* curNode = new TNode(node);
                if(pNode->left)
                    pNode->right = curNode;
                else
                    pNode->left = curNode;
                
                if(pNode->left && pNode->right){
                    pNode = pNode->right;
                }
            }
        }
        
    }
    
    return 0;
}


int xiaomi_3(){
    stack<string> s;
    string input;
    while(cin >> input)
    {
        s.push(input);
    }
    while(!s.empty()){
        cout << s.top();
        if(!s.empty())
            cout << ' ';
    }
    cout << endl;
    
    return 0;
}



vector<string> split(string s,string pattern){
    vector<string> ret;
    if(pattern.empty())
        return ret;
    int start = 0, index = s.find_first_of(pattern,0);
    while(index != string::npos){
        if(start != index){
            ret.push_back(s.substr(start,index -start));
            start = index+1;
            index = s.find_first_of(pattern,start);
        }
    }
    
    if(!s.substr(start).empty())
        ret.push_back(s.substr(start));
    return ret;
}




int xiaomi_4(){
    string str;
    while(getline(cin,str)){
        string pattern = " ";
        vector<string> result = split(str,pattern);
        for(int i = result.size()-1;i>0;i--){
          		cout << result[i] << " ";
        }
        
        cout << result[0];
    }
    
    return 0;
}


//int xiaomi_11(){
//    int n;
//    while(cin >> n){
//        map<int,vector<int>> tree;
//        deque<int> q;
//        pair<int,int>
//        for(int i=0;i < n;i++){
//            int parent,node;
//            cin >> parent >> node;
//            tree[parent].push_back(make_pair(parent, node));
//        }
//        int max_depth=0;
//        int root = 0;
//        q.push_back(root);
//        while(!q.empty()){
//            int cur_node = q.front();
//            q.pop_front();
//            for(int i=0;i<tree[cur_node].size();i++){
//                if(tree[cur_node][])
//                max_depth++;
//                q.push_back(tree[cur_node][i]);
//            }
//        }
//
//
//    }
//    return 0;
//}
