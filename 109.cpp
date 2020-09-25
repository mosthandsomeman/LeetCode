#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    int tag = 0;  
    vector<ListNode*> vec;
    TreeNode *sortedListToBST(ListNode *head)
    {
        TreeNode * root;
        if(head == NULL) return NULL;
        if(head->next== NULL){
            root = new TreeNode(head->val, NULL, NULL);
            return root;
        }
        ListNode *p = head, *q = head, *pre = NULL;
        while(p&&q&&q->next){
            pre = p;
            p = p->next;
            q = q->next;
            if(q) q= q->next;
            else break;
        }
        root = new TreeNode(p->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(p->next);
        return root;
    }
};