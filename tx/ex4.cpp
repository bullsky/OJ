#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }
    cout << random()%n +1 <<endl;
    return 0;
}