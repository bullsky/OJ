#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m,t;
int placeHolder = 100001;


void prePro(vector<vector<int> > & nums1,int n, vector<int>& dp_0) {
    for(int i=0;i<n;i++) {
        int temp = nums1[i][1];
        if(temp>=t) dp_0[t] = min(dp_0[t],nums1[i][0]);
        else dp_0[temp] = min(dp_0[temp],nums1[i][0]);
    }
    for(int i=t-1;i>0;i--) {
        if(dp_0[i]==placeHolder) dp_0[i] = dp_0[i+1];
    }
    dp_0[0] = 0;
}

int func(vector<vector<int> > & nums1, vector<vector<int> > & nums2) {
    if(t==0) return 0;
    vector<int> dp_0(t+1,placeHolder);
    vector<int> dp_1(t+1,placeHolder);
    prePro(nums1,n,dp_0);
    prePro(nums2,m,dp_1);
    int ret = placeHolder;
    for(int i=0;i<=t;i++) {
        ret = min(ret,dp_0[i]+dp_1[t-i]);
    }
    return ret==placeHolder ? -1 : ret;
}

int main() {
    cin >> n >> m >> t;
    vector<vector<int> > nums1(n,vector<int>(2,0));
    vector<vector<int> > nums2(m,vector<int>(2,0));
    for(int i=0;i<n;i++) {
        cin >> nums1[i][0] >> nums1[i][1];
    }
    for(int j=0;j<m;j++) {
        cin >> nums2[j][0] >> nums2[j][1];
    }
    cout << func(nums1,nums2)<<endl;
}