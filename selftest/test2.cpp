#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;


void func(vector<int>& nums,int target) {
    int lo =0 ,hi = nums.size();
    while(lo <hi) {
        int mid = lo + (hi-lo)/2;
        nums[mid] < target ? lo=mid+1 : hi=mid;
    }
    int ret = nums.size()-lo;
    for(int i=lo;i<nums.size();i++) {
        nums[i]--;
    }
    cout << ret <<endl;
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int j;
        cin >> j;
        nums.push_back(j);
    }
    sort(nums.begin(),nums.end());
    vector<int> temp;
    for(int i=0;i<q;i++) {
        int j;
        cin >> j;
        temp.push_back(j);
    }
    for(int j=0;j<q;j++) {
        func(nums,temp[j]);
    }
}