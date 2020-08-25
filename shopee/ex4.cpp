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
    for(char ch:str) {
        if(ch != '[' && ch!=']'&&ch!=','&&ch!='"'&&ch!=' ') {
            // cout << ch <<endl;
            if(isfrist) {
                isfrist = false;
            } else {
                ret += '\\';
                ret += 'n';
            }
            ret += ch;
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