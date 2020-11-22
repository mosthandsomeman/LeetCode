#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cnt  = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                i--;
                cnt++;
            }
        }
        while(cnt > 0){
            nums.push_back(0);
            cnt--;
        }
    }
};