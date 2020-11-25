#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Node
    {
        char c;
        int cnt;
    };
    static bool cmp(Node * a, Node *b){
        return a->cnt > b->cnt;
    }
    string frequencySort(string s) {
        vector<Node*> vec;
        for(int i= 0;i<128;++i){
            Node * tmp = new Node;
            tmp->c = i;
            tmp->cnt = 0;
            vec.push_back(tmp);
        }
        for(int i=0;i<s.size();i++){
            vec[s[i]]->cnt++;
        }
        sort(vec.begin(), vec.end(), cmp);
        s = "";
        for(int i=0;i<vec.size();i++){
            s.insert(s.end(), vec[i]->cnt, vec[i]->c);
        }
        return s;
    }
};