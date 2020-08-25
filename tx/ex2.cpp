#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>


using namespace std;

struct prefixNode {
    int counter;
    bool isWord;
    prefixNode* childs[26];
    // unordered_map<int,prefixNode*> childs;
    prefixNode(bool isword):isWord(isword){
        counter = 0;
        for(int i=0;i<26;i++) childs[i]=nullptr;
    } 
};

int getSum(prefixNode* root,int index) {
    int sum = 0;
    for(int i=0;i<index;i++) {
        if(root->childs[i]) sum += root->childs[i]->counter;
    }
    return sum;
}

bool addWord(prefixNode* root, string& word,int k) {
    prefixNode* node = root;
    int sum = 0;
    for(int i=0;i<word.size();i++) {
        int index = word[i]-'a';
        if(getSum(root,index)>k) break;
        if(!node->childs[index]) {
            node->childs[index] = new prefixNode(true);
            node->counter++;            
        }
        node = node->childs[index];
    }
    
}

string ret = "";

bool preOrder(prefixNode* root,int k) {
    if(!root) return true;
    if(k==1) return false;
    if(root->isWord) {
        k--;
    }
    for(int i=0;i<26;i++) {
        string old = ret;
        ret += ('a'+i);
        if(!preOrder(root->childs[i],k)) return false;
        ret = old;
    }
}

string func(string& str,int k) {
    prefixNode* root = new prefixNode(false);
    int len = str.size();
    for(int i=0;i<len;i++) {
        string tmp = str.substr(i,len-i);
        addWord(root,tmp,k);
    }    
    preOrder(root,k);
    return ret;
}

unordered_map<string,bool> blacklist;

bool isValid(vector<string>& heap,string& tmp) {
    for(auto str : heap) {
        if(str==tmp) return false;
    }
    return true;
}

string func1(string& str,int k) {
    vector<string> heap;
    int len = str.size();
    bool flag = false;
    for(int i=0;i<len;i++) {
        for(int j=i;j<len;j++) {
            string tmp = str.substr(i,j-i+1);
            if(heap.size()<k) heap.push_back(tmp);
            else if(isValid(heap,tmp)) {
                if(!flag) {
                    make_heap(heap.begin(),heap.end());
                    flag = true;
                }
                heap.push_back(tmp);
                // cout << "in " <<tmp <<endl;
                push_heap(heap.begin(),heap.end());
                pop_heap(heap.begin(),heap.end());
                // blacklist[heap.back()] = true;
                // cout << "out " <<heap.back() <<endl;
                heap.pop_back();
            }
        }
    }    
    // for(auto str : heap) cout << str <<endl;
    return heap[0];
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >>k;
    // cout << func(str,k) <<endl;
    cout << func1(str,k) <<endl;
    return 0;
}