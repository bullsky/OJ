#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

int func(vector<vector<int>>& nums) {
    
}

int main() {
    int m,n;
    cin >> n >> m;
    vector<vector<int>> nums(n,vector<int>(m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> nums[i][j];
        }
    }
    cout << func(nums) <<endl;
    return 0;
}