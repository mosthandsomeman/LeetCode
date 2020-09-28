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
    vector<int> tmp;
    void dfs(vector<vector<int>> & res, TreeNode *root, int & cnt, int sum){
        tmp.push_back(root->val);
        cnt += root->val;
        if(root->left==NULL&&root->right==NULL){
            if(cnt == sum) res.push_back(tmp);
            tmp.pop_back();
            cnt -=root->val;
            return;
        }
        else {
            if(root->left) dfs(res, root->left, cnt, sum);
            if(root->right) dfs(res, root->right, cnt, sum);
        }
        tmp.pop_back();
        cnt-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        int cnt = 0;
        if(root) dfs(res, root, cnt,sum);
        return res;
    }
};