#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() < nums2.size()) swap(nums1, nums2);
        set<int> idx(nums1.begin(), nums1.end());
        for(int i=0;i<nums2.size();++i){
            if(idx.find(nums2[i]) != idx.end()){
                res.push_back(nums2[i]);
                idx.erase(nums2[i]);
            }
        }
        return res;
    }
};