#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

int func(string& s,int lo,int hi) {
    int len = s.size();
    while(lo <= hi && lo>=0 && hi<len) {
        if(s[lo] ==s[hi]) {
            lo--;hi++;
        } else break;
    }
    // cout << lo <<hi<<len<<endl;
    return hi == len ? lo+1 : -1;
}



int main() {
    string str;
    cin >> str;
    int len = str.size(),left_min = len;
    for(int i=len-1;i>=1;i--) {
        int left = func(str,i-1,i);
        // cout << left<<endl;
        if(left!=-1) left_min = min(left,left_min);
        left = func(str,i,i);
        // cout << left<<endl;
        if(left!=-1) left_min = min(left,left_min);
    }
    // cout << left_min <<endl;
    for(int i=left_min-1;i>=0;i--) {
        str += str[i];
    }
    cout << str<<endl;
}