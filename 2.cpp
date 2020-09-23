#include<cstdio>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1, *q = l2, *res = NULL, *r = NULL, *tmp = NULL;//β�巨����
		int val = 0, jin = 0;
		while (p != NULL && q != NULL) {
			val = (p->val + q->val + jin) % 10;
			jin = (p->val + q->val + jin) / 10;
			tmp = new ListNode(val);
			if (res == NULL) {
				res = r = tmp;
			}
			else {
				r->next = tmp;
				r = tmp;
			}
			p = p->next, q = q->next;
		}
		while (p != NULL) {
			val = (p->val + jin) % 10;
			jin = (p->val + jin) / 10;
			tmp = new ListNode(val);
			r->next = tmp;
			r = tmp;
			p = p->next;
		}
		while (q != NULL) {
			val = (q->val + jin) % 10;
			jin = (q->val + jin) / 10;
			tmp = new ListNode(val);
			r->next = tmp;
			r = tmp;
			q = q->next;
		}
		if (jin != 0) {
			tmp = new ListNode(jin);
			r->next = tmp;
			r = tmp;
		}
		return res;
	}
};