#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map> 
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n,x;
    cin >> n >>x;
    vector<int> V(n,0),W(n,0);
    for(int i=0;i<n;i++) {
        cin >> W[i] >> V[i];
    }
    vector<int> dp(n+1,0);
    for(int i=0;i<n;i++) {
        for(int j=x;j>=V[i];j--) {
            dp[j] = max(dp[j],dp[j-V[i]]+W[i]); 
        }
    }
    cout << dp[x] <<endl;
    return 0;
}