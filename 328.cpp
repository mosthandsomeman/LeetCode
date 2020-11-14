#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p = head, *q = head->next, *pr = head, *qr = q, *t, *nt;
        int cnt = 3;
        if(q){
            t = q->next;
            while(t){
                nt = t;
                t = t->next;
                if(cnt % 2 == 1){
                    pr->next = nt;
                    pr = nt;
                }
                else {
                    qr->next = nt;
                    qr = nt;
                }
                ++cnt;
            }
            qr->next = NULL;
            pr->next = q;
        }
        return head;
    }
};