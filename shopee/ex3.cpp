#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

int f1(int k) {
    long ret = 0;
    for(int i=k-1;i>0;i--) {
        if(k%i==0) ret++;
    }
    return ret;
}

vector<long> powList(1000100,0);

long fastPow(int x) {
    if(powList[x]!=0) return powList[x];
    long ret = 0;
    ret = fastPow(x>>1)*fastPow(x>>1);
    if(x&0x1) {
        ret *= 2;
    }
    powList[x] = ret;
    return ret;
}

long func(int x) {
    vector<long> dp(x+1,0);
    powList[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=x;i++) {
        dp[i] = dp[i-1];
        int temp = i - f1(i)-1;
        // cout << temp <<endl;
        dp[i] = (dp[i] + fastPow(temp)) % 1000000369;
    }
    return dp[x];
}

int main() {
    int x;
    cin >> x;
    cout << func(x) <<endl;
    return 0;
}