#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

void reverse(string&s,int lo,int hi) {
    while(lo<hi) swap(s[lo++],s[hi--]);
}

void reverse(string& s) {
    int lo = 0,hi = 0,len = s.size();
    while(true) {
        while(lo < len && s[lo]==' ') lo++;
        hi = lo;
        while(hi < len && s[hi]!=' ') hi++;
        reverse(s,lo,hi-1);   
        lo = hi;
        if(hi == len || lo == len) break;
    }
    reverse(s,0,len-1);
}

int main() {
    string str;
    getline(cin,str);
    // cin >> str;
    reverse(str);
    cout << str <<endl;
}