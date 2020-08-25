#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

long func(long n) {
    long ret = 0;
    while(n>10) {
        int x = n%10;
        ret += (10+x);
        n /= 10;
        n --;
    }
    ret += n;
    return ret;
}

int main() {
    int t;
    cin >> t;
    vector<long> ans;
    for(int i=0;i<t;i++) {
        long n;
        cin >> n;
        ans.push_back(func(n));
    }
    for(int i=0;i<ans.size();i++) cout << ans[i] <<endl;
    return 0;
}