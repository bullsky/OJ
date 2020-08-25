#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main() {
    string s;
    vector<string> strlist;
    while(cin >> s) {
        strlist.push_back(s);
        if(cin.get()=='\n') {
            strlist.clear();
        }
    }
}