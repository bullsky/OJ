#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstaclesGrid) {
    if(obstaclesGrid.empty() || obstaclesGrid[0][0]) return 0;
    int rows = obstaclesGrid.size(), cols = obstaclesGrid[0].size();
    if(obstaclesGrid[rows-1][cols-1]) return 0;
    vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));
    dp[1][1] = 1;
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=cols;j++) {
            //初市节点，略过
            if(i==1&&j==1) continue;
            //障碍节点？直接掠过
            if(obstaclesGrid[i-1][j-1]) continue;
            //障碍节点不会增加计数
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[rows][cols];
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> obstaclesGrid(n,vector<int>(m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> obstaclesGrid[i][j];
        }
    }
    cout << uniquePathsWithObstacles(obstaclesGrid) <<endl;
    return 0;
}