#include<vector>
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
    void func(vector<TreeNode*> & vec, vector<TreeNode*> &pv, TreeNode* root, TreeNode* target){
        if(root == NULL) return;
        vec.push_back(root);
        if(root == target) {
            pv = vec;
            vec.pop_back();
            return;
        }
        else{
            func(vec, pv, root->left, target);
            func(vec, pv, root->right, target);
        }
        vec.pop_back();
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode*> vecp, vecq, pv, qv;
        func(vecp, pv, root, p);
        func(vecq, qv, root, q);
        while(pv.size()>qv.size()) { pv.pop_back(); }
        while(pv.size()<qv.size()) { qv.pop_back(); }
        for(int i = pv.size()- 1;i>=0;--i){
            if(pv[i]->val == qv[i]->val) return pv[i];
        }
        return NULL;
    }
};