#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode * merge(ListNode* p, ListNode * q){
        ListNode * head = NULL, *r =NULL, * t = NULL;
        if(!p) return q;
        if(!q) return p;
        while(p && q){
            if(p->val < q->val){
                t = p;
                p = p->next;
            }
            else {
                t = q;
                q = q->next;
            }
            if(head == NULL) head = r = t;
            else {
                r->next = t;
                r = t;
            }
        }
        if(p) r->next = p;
        if(q) r->next = q;
        return head;
    }

    ListNode * mergeSort(ListNode *head) {
        if(head->next == NULL) return head;
        ListNode * p = head, *q = head, *pre = NULL;;
        while(p && q){
            pre = p;
            p = p->next;
            q = q->next;
            if(q) q = q->next;
        }
        q = head;
        if(pre) pre -> next = NULL;
        p = mergeSort(p);
        q = mergeSort(q);
        head = merge(p, q);
        return head;
    }
    ListNode *sortList(ListNode * head) {
        if(head == NULL) return head;    
        head = mergeSort(head);
        return head;
    }
};