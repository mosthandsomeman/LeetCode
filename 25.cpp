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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode * res = NULL, *p = head, *q = NULL, *r = NULL, *t = NULL;
        int cc = 0;
        while(p){
            q = p;
            int cnt = 0;
            while(q) {
                q = q->next;
                ++cnt;
                if(cnt == k) break;
            }
            if(cnt == k){
                if(res == NULL){
                    t = p;
                    p = p->next;
                    res = r = t;
                    r->next = NULL;
                    --cnt;
                    while(p && cnt > 0){
                        t = p;
                        p = p->next;
                        t->next = res;
                        res = t;
                        --cnt;
                    }              
                }
                else {
                    while(p && cnt > 0){
                        t = p;
                        p = p->next;
                        t->next = r->next;
                        r->next = t;
                        --cnt;
                    }
                }
            }
            else {
                if(res == NULL) res = p;
                else r->next = p;
            }
            p = q;
        }
        return res;
    }
};