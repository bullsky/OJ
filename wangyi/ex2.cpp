#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

void func(vector<int>& nums) {
    int len = nums.size();
    
}

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int j=0;j<n;j++) cin >> nums[j];
        func(nums);
    }

}