#include <iostream>
#include <vector>

using namespace std;
int n;

bool check(vector<int>& num1,vector<int>& num2) {
    
}

void func(vector<vector<int>>& nums) {
    vector<int> ret;
    vector<int> visited(n,0);


}

int main() {
    
    cin >>n;
    vector<vector<int>> nums(n,vector<int>(6,1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            cin >> nums[i][j];
        }
    }
    func(nums);
}