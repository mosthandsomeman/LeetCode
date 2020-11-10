#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> idx;
        for(int i=0;i<strs.size();++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(idx.find(s) == idx.end()) {
                vector<string> vec;
                vec.push_back(strs[i]);
                idx[s] = vec;
            }
            else idx[s].push_back(strs[i]);
        }
        for(auto elem : idx) res.push_back(elem.second);
        return res;
    }
};