#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

long func(vector<long>& nums) {
    int len = nums.size();
    vector<long> prefix(len,0),suffix(len,0);
    prefix[0] = nums[0];
    suffix[len-1] = nums[len-1]; 
    for(int i=1;i<len;i++) {
        prefix[i] += prefix[i-1]+nums[i];
        suffix[len-i-1] += suffix[len-i]+nums[len-i-1];
    }
    int lo = 0,hi = len-1;
    long ret = 0;
    while(lo < hi) {
        if(prefix[lo] == suffix[hi]) {
            ret = max(ret,prefix[lo]);
            lo++;hi--;
        } else if(prefix[lo] < suffix[hi]) {
            lo++;
        } else hi--;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<long> nums(n);
    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }
    cout << func(nums) <<endl;
}