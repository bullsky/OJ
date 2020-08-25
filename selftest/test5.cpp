#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n,vector<int>(2,0));
    for(int i=0;i<n;i++) cin >> nums[i][0] >> nums[i][1];
    sort(nums.begin(),nums.end());
    vector<int> dp(n+1,0);
    int ret = 1, len =1;
    dp[len] = nums[0][1];
    for(int i=1;i<n;i++) {
        if(nums[i][1] >= dp[len]) dp[++len] = nums[i][1];
        else {
            *upper_bound(dp.begin(),dp.end(),nums[i][1]) = nums[i][1];
            // int lo = 0,hi = len;
            // while(lo < hi) {
            //     int mid = lo+(hi-lo)/2;
            //     dp[mid] < nums[i][1] ? lo=mid+1 : hi=mid;
            // }
            // dp[lo+1] = nums[i][1];
        }
    }
    cout << len <<endl;
    return 0;
}