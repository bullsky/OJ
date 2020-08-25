#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

bool dfs(string& str,int counter,int k) {
    if(k==str.size()) {
        // cout << counter <<endl;
        return counter==0;
    }
    if(counter <0) return false;
    if(str[k]=='(') {
        return dfs(str,counter+1,k+1);
    } else if(str[k]==')') {
        return dfs(str,counter-1,k+1);
    } else if(str[k]=='*') {
        return dfs(str,counter+1,k+1) || dfs(str,counter-1,k+1) || dfs(str,counter,k+1);
    }
    return false;
}

bool func(string& str){
    if(str.empty()) return true;
    return dfs(str,0,0);
}

int main() {
    string str;
    getline(cin,str);
    string temp;
    temp = str.substr(1,str.size()-2);
    // cout << temp <<endl;
    cout << func(temp) <<endl;
    return 0;
}