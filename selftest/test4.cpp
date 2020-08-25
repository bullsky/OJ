#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;
unordered_map<long, long> m;
  
long solve(long n){  //记忆搜索法
    if(m.count(n)) return m[n]; //如果已有直接返回
    long count = 0;
    if((n&1) != 1) count = solve(n>>1) + solve((n>>1)-1);  //n为偶数
    else count = solve(n>>1);  //n为奇数
    m[n] = count;
    return count;
}

long func(long n) {
    int len = log2(n);
    vector<vector<int>> dp(n+1,vector<int>(len+1,0));
    for(int i=0;i<=len;i++) dp[0][i]=dp[1][i]=1;
    dp[1][0] = dp[2][0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=len;j++) {
            long sum = 0;
            for(int k=0;k<3;k++) {
                long temp = i-k*pow(2,j);
                if(temp >=0) sum += dp[temp][j-1];
            }
            dp[i][j] = sum;
        }
    }
    return dp[n][len];
}

int main() {
    long n;
    cin >> n;
    cout << func(n) <<endl;
    return 0;
}