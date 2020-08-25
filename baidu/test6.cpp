#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode* parent;
    vector<TreeNode*> childs;
};

int ret = 0;

bool dfs(TreeNode* root,TreeNode* node,int depth) {
    if(!root) return false;
    if(root==node) {
        ret = depth;
        return true;
    }
    for(TreeNode* child : root->childs) {
        if(dfs(child,node,depth+1)) return true;
    }
    return false;
}

int depth(TreeNode* root,TreeNode* node) {
    if(!root || !node) return -1;
    return dfs(root,node,0) ? ret : -1;
}

TreeNode* func(TreeNode* root,TreeNode* node1,TreeNode* node2) {
    if(!root || !node1 || !node2) return nullptr;
    if(node1==node2) return node1;
    vector<TreeNode*> path1,path2;
    while(node1!=root) {
        path1.push_back(node1);
        node1 = node1->parent;
    }
    path1.push_back(root);
    while(node2!=root) {
        path2.push_back(node2);
        node2 = node2->parent;
    }
    path2.push_back(root);
    int i=path1.size()-1,j=path2.size()-1;
    TreeNode* ret = nullptr;
    for(;i>=0&&j>=0;i--,j--) {
        if(path1[i]!=path2[j]) ret = path1[i+1]; 
    }
    if(!ret) {
        if(i<0) ret = path1[0];
        else ret = path2[0];
    }
    return ret;
}




