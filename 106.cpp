#include<vector>
#include<algorithm>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if(inorder.size() == 0) return NULL;
        TreeNode * root = new TreeNode(postorder[postorder.size()-1]);
        int i = 0;
        for(;i<inorder.size();++i){
            if(inorder[i] == root->val) break;
        }
        vector<int> leftIn(inorder.begin(), inorder.begin()+i);
        vector<int> leftPo(postorder.begin(), postorder.begin() +  i);
        vector<int> rightIn(inorder.begin()+i+1, inorder.end());
        vector<int> rightpo(postorder.begin()+i,postorder.end()-1);
        root->left = buildTree(leftIn, leftPo);
        root->right = buildTree(rightIn, rightpo);
        return root;
    }
};