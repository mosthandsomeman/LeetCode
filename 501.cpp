#include<vector>
#include<queue>
#include<map>
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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> vec;
        map<int, int> mmap;
        queue<TreeNode*> q;
        int max = 0;
        if(root) q.push(root);
        while(!q.empty()){
            TreeNode * top = q.front();
            q.pop();
            if(mmap.find(top->val) != mmap.end()) mmap[top->val]++;
            else mmap[top->val] = 1;
            if(mmap[top->val] > max) max = mmap[top->val];
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        for(auto elem:mmap){
            if(elem.second == max) vec.push_back(elem.first);
        }
        return vec;
    }
};