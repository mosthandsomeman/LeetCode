#include"bits/stdc++.h"
 using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
vector<vector<int>> res;
    vector<int> lay, cnt;
    void layerOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root == NULL)
            return;
        q.push(root);
        int last = 1, front = 0, rear = 1;
        cnt.push_back(1);
        while (q.size() > 0)
        {
            TreeNode *tmp = q.front();
            q.pop();
            lay.push_back(tmp->val);
            ++front;
            if (tmp->left)
            {
                q.push(tmp->left);
                ++rear;
            }
            if (tmp->right)
            {
                q.push(tmp->right);
                ++rear;
            }
            if (front == last)
            {
                last = rear;
                cnt.push_back(rear - front);
            }
        }
    }
    bool isEvenOddTree(TreeNode *root)
    {
        layerOrder(root);
        for(int i=0, j = 0;i<cnt.size();++i){
            if(i % 2 == 1) reverse(lay.begin() + j, lay.begin() + j+ cnt[i]);
            vector<int> tt(lay.begin() + j, lay.begin() + j+ cnt[i]);
            if(tt.size() != 0)res.push_back(tt);
            j += cnt[i];
        }
        for(int i=0;i<res.size();++i){
            if(res[i][0] % 2 == i % 2) return false;
            for(int j= 0;j<res[i].size() - 1;++j){
                if(res[i][j] % 2 == i % 2 || res[i][j] >= res[i][j+ 1]) return false;
            }
            if(res[i][res[i].size() - 1] % 2 == i % 2) return false;
        }
        return true;
    }
};