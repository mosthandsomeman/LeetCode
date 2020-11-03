//万能头
#include<bits/stdc++.h>

using namespace std;

//默认最大值
#define _T101_ 101  
#define _T1001_ 1001
#define _T10001_ 10001
#define _T100001_ 100001
#define _INF_ 1000000000

//通用树节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class createTree
{
public:
    createTree();
    ~createTree();

public:
    //用vec创建树   vec补充为满二叉树 NULL 用-1 代替
    TreeNode * createTreeByVec(vector<int> vec);
    
    //根据先序中序创建树
    TreeNode * createTreeByPreAndIn(vector<int> preOrder, vector<int> inOrder);

    //根据中序后序创建树
    TreeNode * createTreeByInAndPost(vector<int> inOrder, vector<int> postOrder);

    //递归
    //先序遍历
    void preOrder(vector<int> & vec, TreeNode * root);

    //中序遍历
    void  InOrder(vector<int> & vec, TreeNode * root);

    //后序遍历
    void  postOrder(vector<int> & vec, TreeNode * root);

    //层次遍历
    void  layerOrder(vector<int> & vec, TreeNode * root);

    //迭代
    //先序遍历
    void preOrder_iter(vector<int> & vec, TreeNode * root);

    //中序遍历
    void  InOrder_iter(vector<int> & vec, TreeNode * root);

    //后序遍历
    void  postOrder_iter(vector<int> & vec, TreeNode * root);

};

//图的类
class graphNode
{
public:
    int G[_T1001_][_T1001_];
    bool vis[_T1001_];

    graphNode(){}

    ~graphNode(){}

    //深度优先
    void dfs();

    //广度优先
    void bfs();

    //最小路径 迪杰斯特拉
    void Dijkstra();

    //最小生成树
    //普拉姆算法
    void Prim();

    //克鲁斯卡尔算法
    void Kruskal();

};