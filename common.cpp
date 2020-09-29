#include "common.h"

createTree::createTree(){

}

createTree::~createTree(){

}

TreeNode *createTree::createTreeByVec(vector<int> vec)
{
    return NULL;
}

//根据先序中序创建树
TreeNode *createTree::createTreeByPreAndIn(vector<int> preOrder, vector<int> inOrder)
{
    if (preOrder.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(preOrder[0]);
    int i = 0;
    for (; i < inOrder.size(); ++i)
    {
        if (inOrder[i] == root->val)
            break;
    }
    vector<int> leftPre(preOrder.begin() + 1, preOrder.begin() + i + 1);
    vector<int> leftIn(inOrder.begin(), inOrder.begin() + i);
    vector<int> rightPre(preOrder.begin() + i + 1, preOrder.end());
    vector<int> rightIn(inOrder.begin() + i + 1, inOrder.end());
    root->left = createTreeByPreAndIn(leftPre, leftIn);
    root->right = createTreeByPreAndIn(rightPre, rightIn);
    return root;
}

//根据中序后序创建树
TreeNode *createTree::createTreeByInAndPost(vector<int> inOrder, vector<int> postOrder)
{

    if (inOrder.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(postOrder[postOrder.size() - 1]);
    int i = 0;
    for (; i < inOrder.size(); ++i)
    {
        if (inOrder[i] == root->val)
            break;
    }
    vector<int> leftIn(inOrder.begin(), inOrder.begin() + i);
    vector<int> leftPo(postOrder.begin(), postOrder.begin() + i);
    vector<int> rightIn(inOrder.begin() + i + 1, inOrder.end());
    vector<int> rightpo(postOrder.begin() + i, postOrder.end() - 1);
    root->left = createTreeByInAndPost(leftIn, leftPo);
    root->right = createTreeByInAndPost(rightIn, rightpo);
    return root;
}

//递归
//先序遍历
void createTree::preOrder(vector<int> &vec, TreeNode *root)
{
    if (root == NULL)
        return;
    vec.push_back(root->val);
    preOrder(vec, root->left);
    preOrder(vec, root->right);
}

//中序遍历
void createTree::InOrder(vector<int> &vec, TreeNode *root)
{
    if (root == NULL)
        return;
    preOrder(vec, root->left);
    vec.push_back(root->val);
    preOrder(vec, root->right);
}

//后序遍历
void createTree::postOrder(vector<int> &vec, TreeNode *root)
{
    if (root == NULL)
        return;
    preOrder(vec, root->left);
    preOrder(vec, root->right);
    vec.push_back(root->val);
}

//层次遍历
void createTree::layerOrder(vector<int> &vec, TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        vec.push_back(tmp->val);
        if (tmp->left)
            q.push(root->left);
        if (tmp->right)
            q.push(root->right);
    }
}

//先序遍历 迭代
void createTree::preOrder_iter(vector<int> &vec, TreeNode *root)
{
    stack<TreeNode *> st;

    TreeNode *curr = root;

    // 1.退出最外层迭代的条件是，指针指向null，且栈为空
    while (curr != NULL || !st.empty())
    {
        // 2.内层循环按顺序入栈，同时更新当前指针
        // 4.这时候也可能是开始遍历右节点
        while (curr != NULL)
        {
            st.push(curr);
            vec.insert(vec.begin(), curr->val);
            curr = curr->left;
        }
        // 3.返回父节点，并将指针指向右节点
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}

//中序遍历 迭代
void createTree::InOrder_iter(vector<int> &vec, TreeNode *root)
{
    stack<TreeNode *> st;

    TreeNode *curr = root;

    // 1.退出最外层迭代的条件是，指针指向null，且栈为空
    while (curr != NULL || !st.empty())
    {
        // 2.内层循环按顺序入栈，同时更新当前指针
        // 4.这时候也可能是开始遍历右节点
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        // 3.返回父节点，并将指针指向右节点
        curr = st.top();
        st.pop();
        vec.insert(vec.begin(), curr->val);
        curr = curr->right;
    }
}

//后序遍历 迭代
void createTree::postOrder_iter(vector<int> &vec, TreeNode *root)
{
    stack<TreeNode *> st;

    if (root == NULL)
        return;

    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        vec.insert(vec.begin(), node->val);

        if (node->left != NULL)
        {
            st.push(node->left);
        }
        if (node->right != NULL)
        {
            st.push(node->right);
        }
    }
}