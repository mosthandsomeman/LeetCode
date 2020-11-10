#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        multiset<int> vec(prices.begin(), prices.end());
        int res = 0;
        for(int i =0;i<prices.size()- 1;++i){
            vec.erase(vec.find(prices[i]));
            int m = *vec.rbegin();
            if(m - prices[i] > res) res = m - prices[i];
        }
        return res;
    }
};