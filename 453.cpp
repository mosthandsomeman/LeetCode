#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0;
        multiset<int> ms(nums.begin(), nums.end());
        while (*ms.begin() != *ms.rbegin()) {
            int dis = *ms.rbegin() - *ms.begin();
            ms.erase(ms.find(*ms.rbegin()));
            ms.insert(*ms.begin());
            cnt += dis;
        }
        return cnt;
    }
};