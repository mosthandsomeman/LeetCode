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
        map<int, bool> tag;
        for(auto elem:remain) tag[elem] = false;
        for(auto elem :remain){
            if(!tag[elem]) {
                dfs(remain, elem);
                tag[elem] = true;
            }
        }
        tmp.pop_back();
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {      
        multiset<int> remain(nums.begin(), nums.end());
        map<int, bool> tag;
        for(int i=0;i<nums.size();++i) tag[nums[i]] = false;
        for(int i =0;i<nums.size();++i){
            if(!tag[nums[i]]) {
                dfs(remain, nums[i]);
                tag[nums[i]] = true;
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};