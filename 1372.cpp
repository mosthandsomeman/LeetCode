#include "bits/stdc++.h"
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int res;
    void dfs(TreeNode * root, int tag, int leng){
        ++leng;
        if(leng > res) res = leng;
        if(!root->left && !root->right) return;
        if(!tag) {
            if(root->left) dfs(root->left, 1, leng);
            if(root->right) dfs(root->right,0, 1);
        }
        else {
            if(root->right) dfs(root->right, 0, leng);
            if(root->left) dfs(root->left, 1, 1);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        res = -1;
        dfs(root, 0, 0);
        return res - 1;
    }
};