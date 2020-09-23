#include <cstdio>
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode *p = head, *q = p, *t, *h, *r = NULL;
		head = NULL;
		int cnt = 0, curV = 0;
		while (p)
		{
			if (cnt == 0) {
				++cnt, curV = p->val;
				p = p->next;
			}
			else {
				if (p->val == curV) {
					++cnt;
					p = p->next;
				}
				else {
					curV = p->val;
					if (cnt == 1) {
						t = q;
						q = p;
						p = p->next;
						if (head == NULL) head = r = t;
						else {
							r->next = t;
							r = r->next;
						}
					}
					else {
						t = q;
						q = p;
						p = p->next;
						while (t && cnt >0) {
							h = t;
							t = t->next;
							delete(h);
							--cnt;
						}
						cnt = 1;
					}
				}
			}
		}
		if (cnt == 1) {
			if (head == NULL) head = r = q;
			else {
				r->next = q;
				r = r->next;
			}
		}
		else {
			t = q;
			while (t && cnt > 0) {
				h = t;
				t = t->next;
				delete(h);
				--cnt;
			}
			cnt = 1;
		}
		r->next = NULL;
		return head;
	}
};