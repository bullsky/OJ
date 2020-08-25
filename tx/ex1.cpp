#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct node
{
    /* data */
    int val;
    node* next;
    node(int v,node* n=nullptr):val(v),next(n){}
};


void func(vector<int>& nums,int k) {
    auto iter = nums.begin()+k-1;
    nums.erase(iter);
    for(auto num:nums) cout << num <<" ";
    cout <<endl;
}

void func1(node* root,int k) {
    node* pre = root;
    while(k>1) {
        pre = pre->next;
        k--;
    }
    pre->next = pre->next->next; 
    node* cur=root;
    while(cur=cur->next) {
        cout << cur->val <<" ";
    }
    cout <<endl;
}

int main() {
    int n,k;
    cin >> n >> k;
    // vector<int> nums(n,0);
    node* root = new node(0);
    node* cur = root;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        cur->next = new node(x);
        cur=cur->next;
    }
    // cout <<"sss"<<endl;
    func1(root,k);
    return 0;
}