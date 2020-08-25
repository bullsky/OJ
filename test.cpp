#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

void func(int i,int n) {
    cout << fixed << setprecision(6) << (double)100*i/n <<endl;
}

int main() {
    string str,tmp;
    stringstream ss;
    vector<string> strlist;
    while(cin >> str) {
        ss << str;
        while(getline(ss, tmp,',')) {
            strlist.push_back(tmp);
        }
        strlist.clear();
        ss.clear();
    }
}