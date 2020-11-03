#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    void getZeroNum(string s, int & n0, int & n1){
        for(int i=0;i<s.size();++i){
            if(s[i] == '0') n0++;
            else n1++;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ** dp = new int *[m+ 1];
        for(int i =0;i<m + 1;++i){
            dp[i] = new int[n + 1];
            memset(dp[i], 0, sizeof(int) *(n+1));
        }
        for(int i =0;i<strs.size();++i){
            int n0 = 0, n1 = 0;
            getZeroNum(strs[i], n0, n1);
            for(int j = m;j >= n0;--j){
                for(int t = n;t >= n1;--t){
                    dp[j][t] = max(1 + dp[j - n0][t - n1], dp[j][t]);
                }
            }
        }
        return dp[m][n];
    }
};