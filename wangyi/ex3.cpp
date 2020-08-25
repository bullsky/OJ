#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

void addTime(int seconds) {
    int hours = seconds/3600;
    int minutes = (seconds - hours*3600)/60;
    seconds = seconds - 3600*hours - 60*minutes;
    hours += 8;
    string suffix = hours <= 12 ? "am" :"pm";
    string hpre = hours < 10 ? "0":"";
    string mpre = minutes < 10 ? "0":"";
    string spre = seconds < 10 ? "0":"";
    cout <<hpre<<hours<<":"<<mpre<<minutes<<":"<<spre<<seconds<<" "<<suffix<<endl;
}

int func(vector<int>& nums_a,vector<int>& nums_b) {
    int len = nums_a.size();
    vector<int> dp(len+1,0);
    // dp[0] = nums_a[0];
    for(int i=1;i<=len;i++) {
        int sum1 = dp[i-1]+nums_a[i-1];
        int sum2 = i>=2 ? dp[i-2]+nums_b[i-1] : 1<<30;
        dp[i] = min(sum1,sum2);
    }
    // cout << dp[len] <<endl;
    return dp[len];
}

int main() {
    int t;
    cin >> t;
    vector<int> ret;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        vector<int> nums_a(n,0);
        vector<int> nums_b(n,0);
        for(int j=0;j<n;j++) cin >> nums_a[j];
        for(int j=0;j<n-1;j++) cin >> nums_b[j+1];
        ret.push_back(func(nums_a,nums_b));
    }
    for(auto ans : ret) {
        addTime(ans);
    }

}