#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
	bool res;
	void dfs(string s, string word, int idx, set<string> dict) {
		word.insert(word.size(), 1, s[idx]);
		if (idx == s.size() - 1) {
			if (dict.find(word) != dict.end()) {
				res = true;
                return;
			}
			word.pop_back();
			return;
		}
		if (dict.find(word) != dict.end()) {
			string w1 = "";
			dfs(s, w1, idx + 1, dict);
		}
		dfs(s, word, idx + 1, dict);
		word.pop_back();
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		set<string> dict(wordDict.begin(), wordDict.end());
        res = false;
		string tmp = "", word = "";
		dfs(s, word, 0, dict);
		return res;
	}
};