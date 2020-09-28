#include<queue>
#include<vector>
#include<iostream>
using namespace std;
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		queue<Node*> q;
		vector<Node*> vec;
		if (root == NULL) return NULL;
		q.push(root);
		int front = 0, last = 1, rear = 1;
		while (!q.empty()) {
			Node * tmp = q.front();
			q.pop();
			front++;
			vec.push_back(tmp);
			if (tmp->left) {
				q.push(tmp->left);
				rear++;
			}
			if (tmp->right) {
				q.push(tmp->right);
				rear++;
			}
			if (front == last) {
				last = rear;
				Node * t = new Node(101);
				vec.push_back(t);
			}
		}
		for (int i = 0; i < vec.size() - 1; ++i) {
			if (vec[i]->val != 101) {
				if (vec[i + 1]->val != 101) 
					vec[i]->next = vec[i + 1];
				else 
					vec[i]->next = NULL;
			}
		}
		return root;
	}
};