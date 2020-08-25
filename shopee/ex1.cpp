#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

string func(string& str) {
    string ret = "\"";
    bool isfrist = true;
    int lo = 0,hi=0,counter = 0 ;
    for(int i=0;i<str.size();i++) {
        char ch = str[i];
        if(ch == '"') {
            if(counter==0) {
                lo = i+1;
                counter++;
            } else {
                hi = i-1;
                counter = 0;
                string temp = str.substr(lo,hi-lo+1);
                if(isfrist) {
                    isfrist = false;
                } else {
                    ret += '\\';
                    ret += 'n';
                }
                ret += temp;
            }
        }
    }
    ret += "\"";
    return ret;
}


int main() {
    string str;
    getline(cin,str);
    // cout << "a\\nb\\nc\\nd" <<endl;
    cout << func(str) <<endl;
    return 0;
}