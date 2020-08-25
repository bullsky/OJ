#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map> 
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

string func(string& str,int k) {
    if(str.size()<=k) return "0";
    stack<int> st;
    vector<int> del_flag(str.size(),0);
    for(int i=0;i<str.size();i++) {
        char ch = str[i];
        if(st.empty() || ch>=str[st.top()]) st.push(i);
        else {
            while(k && !st.empty() && ch<str[st.top()]) {
                // cout << st.top() <<endl;
                del_flag[st.top()] = 1;
                st.pop();k--;
            }
            st.push(i);
        }
        if(!k) break;
    }
    while(k) {
        del_flag[st.top()] = 1;
        st.pop();k--;
    }
    string ret = "";
    bool flag = false;
    for(int i=0;i<str.size();i++) {
        if(!del_flag[i]) {
            if(str[i]=='0' && flag == false) continue;
            else if(str[i]!='0' && flag == false) flag = true;
            ret += str[i];
        }
    }
    return ret=="" ? "0" : ret;
}

int main() {
    string str;
    int k;
    cin >> str >>k;
    cout << func(str,k) <<endl;
    return 0;
}