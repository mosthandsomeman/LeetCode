#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, pre = prices[0];
        for(int i=1;i<prices.size();++i){
            if(prices[i] > pre){
                res += prices[i] - pre;
                pre = prices[i];
            }
            else pre = prices[i];
        }
        return res;
    }
};