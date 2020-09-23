#include<string>
#include<cstdio>
#include<iostream> 
int dp[1001][1001];
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0 || s.size() == 1) return s;
		int len = s.size(), ans = 1, max = 0;
		string res = "";
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < len; ++i) {
			dp[i][i] = 1;
			if (max == 0) {
				max = 1;
				res = s.substr(i, 1);
			}
			if (i < len - 1) {
				if (s[i] == s[i + 1]) {
					dp[i][i + 1] = 1;
					ans = 2;
					if (ans > max) {
						res = s.substr(i, 2);
						max = ans;
					}
				}
			}
		}
		for (int L = 3; L <= len; ++L) {
			for (int i = 0; i + L - 1 < len; ++i) {
				int j = i + L - 1;
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
					dp[i][j] = 1;
					ans = L;
					if (ans > max) {
						res = s.substr(i, L);
						max = ans;
					}
				}
			}
		}
		return res;
	}
};