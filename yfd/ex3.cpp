#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

// int func(int n,int k) {
//     vector<vector<int>> dp(n*n,vector<int>(n,0));
//     for(int i=0;i<dp.size();i++) dp[i][1] = 2;
//     for(int i=0;i<dp.size();i++) {
//         for(int j=2;j<n;j++) {
//             dp[i][j] = max(dp[i][j],dp[])
//         }
//     }
// }

int func(int n,int k) {
    int counter = 0;
    for(int i=2;i<n-k;i++) {
        counter += i;
    }
    return counter;
}

int main() {
    int n,k;
    cin >> n >>k;
    cout << func(n,k) <<endl;
    return 0;
}