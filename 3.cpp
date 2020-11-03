#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int idx[130];
		int max = 0, cnt;
		for (int i = 0; i < s.size(); ++i) {
			memset(idx, 0, sizeof(idx));
			idx[s[i]] = 1, cnt = 1;
			for (int j = i + 1; j < s.size(); ++j) {
				if (idx[s[j]] == 0) {
					idx[s[j]] = 1, ++cnt;
				}
				else
				{
					break;
				}
			}
			max = max > cnt ? max : cnt;
		}
		return max;
	}
};