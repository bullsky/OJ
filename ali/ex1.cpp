#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

int max_val = 0;

int func(vector<vector<int>>& nums,int d) {
    int n = nums.size(),counter = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int diff = max_val-nums[i][j];
            if(d!=1 && diff%d != 0) {
                return -1;
            } else {
                counter += diff/d;
            }
        }
    }
    return counter;
}

int main() {
    int n,d;
    cin >> n >>d;
    vector<vector<int>> nums(n,vector<int>(n,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> nums[i][j];
            max_val = max(max_val,nums[i][j]);
        }
    }
    cout << func(nums,d) <<endl;
    return 0;
}