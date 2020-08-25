#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

int cur = 0;

void dfs(vector<vector<int> >& nums,int i,vector<int>& visited) {
    if(visited[i]) {
        return;
    }
    int len = nums.size();
    visited[i] = 1;
    for(int j=1;j<len;j++) {
        if(nums[i][j]==1) {
            if(cur!=i) nums[cur][j] = 2;
            dfs(nums,j,visited);
        }
    }
    visited[i] = 0;
}

int func(vector<vector<int> >& nums) {
    int ret = 0;
    int len = nums.size();
    for(int i=1;i<len;i++) {
        for(int j=1;j<i;j++) {
            if(nums[i][j]>0 && nums[j][i]>0) ret++;
        }
    }
    return ret;
}

int main() {
    int n,m;
    cin >> n>>m;
    vector<vector<int> > nums(m+1,vector<int>(m+1,0));
    for(int i=0;i<m;i++) {
        int x,y;
        cin >> x >>y;
        nums[x][y] = 1;
        // cin >> nums[i][0] >> nums[i][1];
    }
    vector<int> visited(m+1,0);
    for(int i=1;i<=n;i++) {
        cur = i;
        dfs(nums,i,visited);
    }
    cout << func(nums) <<endl;

}