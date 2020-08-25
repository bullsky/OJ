#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> ret;
int tree_size = 0;

inline int lchild(int x) {return 2*x + 1;}
inline int rchild(int x) {return 2*x + 2;}
inline int parent(int x) {return x/2;}
inline bool isintree(int x) {return x < tree_size;}
inline bool isinlevel(int x,int level_max) {return x <tree_size && x < level_max;}

void func(vector<int>& nums) {
    int len = nums.size();
    ret.push_back(nums[0]);
    int cur = 0,level_max = 0;
    while(isintree(cur = lchild(cur))) {
        ret.push_back(nums[cur]);
        level_max = cur;
    }
    level_max = lchild(cur);
    cur++;
    // cout << level_max <<" "<<cur <<endl;
    while(true) {
        if(isinlevel(cur,level_max)) ret.push_back(nums[cur++]);
        else {
            level_max = parent(level_max);
            cur = parent(cur);
            // cout << level_max <<" "<<nums[cur] <<endl;
            if(cur == 0) break;
        }
    }
    cur = 0;
    vector<int> tmp;
    while(isintree(cur = rchild(cur))) {
        // cout << cur <<endl;
        tmp.push_back(nums[cur]);
    }
    for(int i=tmp.size()-2;i>=0;i--) ret.push_back(tmp[i]);
    // cout << cur<<endl;
    for(auto i : ret) {
        cout << i <<" ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    tree_size = n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++) cin >> nums[i];
    func(nums);
    return 0;
}