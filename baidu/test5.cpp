#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9

// 7 4 1
// 8 5 2
// 9 6 3

// 0,0 -> 2,2
// 0,1 -> 1,2
// 1,0 -> 2,1

void func(vector<vector<int>>& matrix) {
    int N = matrix.size();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N/2;j++) {
            swap(matrix[i][j],matrix[i][N-1-j]);
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N-1-i;j++) {
            swap(matrix[i][j],matrix[N-1-j][N-1-i]);
        }
    }
}

struct LinkNode
{
    /* data */
    int val;
    LinkNode* next;
    LinkNode(int v,LinkNode* n):val(v),next(n){}
};

LinkNode* swap2(LinkNode* preNode) {
    LinkNode* node = preNode->next;
    if(!node->next) return NULL;
    preNode->next = node->next;
    node->next = node->next->next;
    preNode->next->next = node;
    return node;
}

LinkNode* func1(LinkNode* head) {
    LinkNode* newHead = new LinkNode(0,head);
    LinkNode* preNode = newHead;
    while(preNode=swap2(preNode));
    head = newHead->next;
    delete newHead;
    return head;
}




int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    func(matrix);
    int N = matrix.size();
    for(int i=0;i<N;i++) {
        for(int j =0;j<N;j++) {
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }
}