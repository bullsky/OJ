#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map> 
#include <algorithm>
#include <iomanip>

using namespace std;

int n,p;
const int start = 0;
int end_p = 0;
int sumPath = 1<<30,tmpPath = 0;
vector<int> visited;
vector<vector<int>> matrix;
void func(int k) {
    if(k==end_p) {
        sumPath = min(tmpPath,sumPath);
        return;
    }
    if(visited[k]) return;
    visited[k] = 1;
    for(int i=0;i<n;i++) {
        if(matrix[k][i]>0) {
            tmpPath += matrix[k][i];
            func(i);
            tmpPath -= matrix[k][i];
        }
    }
    visited[k] = 0;
}

int main() {
    
    cin >> n >>p;
    // vector<int> A(p,0),B(p,0),T(p,0);
    // vector<vector<int>> matrix(n,vector<int>(n,0));
    matrix.assign(n,vector<int>(n,0));
    for(int i=0;i<p;i++) {
        // cin >> A[i] >> B[i] >>T[i];
        int a,b,t;
        cin >> a >>b>>t;
        matrix[a][b] = t;
    }
    cin >> end_p;
    visited.assign(n,0);
    func(start);
    cout << sumPath <<endl;
    return 0;
}