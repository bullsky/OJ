#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

bool op1(string& str,int i) {
    if(str[i]=='0' || str[i+1]=='9') return false;
    str[i] -= 1;str[i+1] += 1;
    return true;
}

bool op2(string& str,int i) {
    if(str[i]=='9' || str[i+1]=='0') return false;
    str[i] += 1;str[i+1] -= 1;
    return true;
}

void dfs(string& str,int i,long& counter) {
    if(i==str.size()-1) {
        // strset.insert(str);
        counter++;
        return;
    }
    string tmp(str);
    while(op1(str,i)) {
        dfs(str,i+1,counter);
    }
    str = tmp;
    while(op2(str,i)) {
        dfs(str,i+1,counter);
    }    
}

long dfs(string& str,int i) {
    if(i==str.size()-1) {
        return 1;
    }
    long counter = 0;
    string tmp(str);
    while(op1(str,i)) {
        counter += dfs(str,i+1);
    }
    str = tmp;
    while(op2(str,i)) {
        counter += dfs(str,i+1);
    }
    return counter%1000000007;
}


long func(string& str) {
    // set<string> strset;
    // long counter = 0;
    // dfs(str,0,counter);
    // return counter%1000000007;
    return dfs(str,0);
}

int main() {
    int q;
    cin >> q;
    vector<long> ans;
    vector<string> input;
    string str;
    for(int i=0;i<q;i++) {
        cin >> str;
        input.push_back(str);
        // ans.push_back(func(str));
    }
    for(auto str : input) cout << func(str) <<endl;
    return 0;
}