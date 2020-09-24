#include<vector>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		if (hand.size() % W != 0) return false;
		map<int, int> m;
		for (int i = 0; i < hand.size(); ++i) {
			if (m.find(hand[i]) == m.end()) m[hand[i]] = 1;
			else m[hand[i]]++;
		}
		int cnt = hand.size() / W;
		while (cnt > 0) {
			int bg = m.begin()->first, k = W, tag = 1;
			while (k > 0) {
				if (m.find(bg) != m.end() && m[bg] > 0) {
					k--;
					m[bg]--;
					if (m[bg] == 0) m.erase(m.begin());
					bg += 1;
				}
				else {
					tag = 0;
					break;
				}
			}
			--cnt;
			if (!tag) break;
		}
		if (m.size() != 0) return false;
		else return true;
	}
};