#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

unordered_map<int,int> umap;
vector<int> ret;

int func(vector<int>& inOrder,int i_l,int i_h) {
    // cout << p_l <<','<<p_h<<' '<<i_l<<' '<<i_h<<endl;
    if(i_l>i_h) return 0;
    int index = i_l+(i_h-i_l)/2;
    int lsum = func(inOrder,i_l,index-1);
    int rsum = func(inOrder,index+1,i_h);
    ret[index] = lsum + rsum;
    return ret[index]+inOrder[index];
}

int main() {
    vector<int> preOrder, inOrder;
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss >> x) preOrder.push_back(x);
    ss.clear();
    getline(cin,s);
    ss.str(s);
    while(ss >> x) inOrder.push_back(x);
    for(int i=0;i<inOrder.size();i++) {
        umap[inOrder[i]] = i;
    }
    ret.assign(inOrder.size(),0);
    func(inOrder,0,inOrder.size()-1);
    for(auto r : ret ) cout << r <<" ";
    cout << endl;
}