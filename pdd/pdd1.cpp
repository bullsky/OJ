#include <iostream>
#include <vector>

using namespace std;

void func(vector<int>& nums,int k) {
    if(!k)  {
        cout << "paradox" <<endl;
        return;
    }
    int len = nums.size(),counter = 0;
    for(int i=0;i<len;i++) {
        k -= nums[i];
        if(k==0) {
            cout << "paradox" <<endl;
            return;
        } else if(k<0) {
            k = -k;
            counter ++;
        }
    }
    cout << k<<" "<<counter<<endl;
}

int main() {
    int k,n;
    cin >>k>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }
    func(nums,k);
}