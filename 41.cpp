#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() + 1;
        for(int i=0;i<n - 1;++i) {
            if(nums[i] <= 0) nums[i] = n;
        }
        for(int i=0;i<n- 1;++i){
            if(abs(nums[i]) <= n - 1) nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        for(int i=0;i<n - 1;++i){
            if(nums[i] > 0) return i + 1; 
        }
        return n;
    }
};