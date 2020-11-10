#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<vector<int>> res;
    vector<int> tmp;
    void dfs(multiset<int> remain, int data){
        tmp.push_back(data);
        remain.erase(remain.find(data));
        if(remain.size() == 0) {
            res.insert(tmp);
            tmp.pop_back();
            return;
        }
        for(auto elem :remain)  dfs(remain, elem);
        tmp.pop_back();
    }
    vector<vector<int>> permute(vector<int>& nums) {      
        multiset<int> remain(nums.begin(), nums.end());
        for(int i =0;i<nums.size();++i){
            dfs(remain, nums[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};