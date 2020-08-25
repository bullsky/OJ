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

long Cmn(int m,int n) {
    if(m == 0) return 0;
    if(n == 0) return 1;
    return Cmn(m-1,n)+Cmn(m,n);
}

long func(string& str) {
    long sum = 0;
    int len = str.size();
    for(char ch : str) sum += (ch-'0');
    for(int i=0;i<len;i++) {
        
    }
    return ;
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