 #include<bits/stdc++.h>
 using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode * p = head->next, *q = NULL, *r = NULL, *pre = NULL;
        head->next = NULL;
        while(p){
            r = p;
            p = p->next;
            q  = head;
            pre = NULL;
            while(q && q->val < r->val){
                pre = q;
                q = q->next;
            }
            if(pre == NULL) {
                r->next = head;
                head = r;
            }
            else {
                r->next = q;
                pre->next = r;
            }
        }
        return head;
    }
};