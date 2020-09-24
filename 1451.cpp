#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct Node {
	string s;
	int t;
	Node(string _s, int _t) :s(_s), t(_t) {}
};
bool cmp(Node a, Node b) {
	if (a.s.length() != b.s.length()) return a.s.length() < b.s.length();
	else return a.t < b.t;
}
class Solution {
public:
	vector<Node> vec;
	string arrangeWords(string text) {
		text[0] += 32;
		istringstream is(text);
		string word;
		int idx = 1;
		while (is >> word) {
			Node tmp(word, idx);
			vec.push_back(tmp);
			idx++;
		}
		sort(vec.begin(), vec.end(), cmp);
		vec[0].s[0] -= 32;
		word = "";
		for (int i = 0; i < vec.size() - 1; ++i) {
			word+= vec[i].s +" ";
		}
		word += vec[vec.size() - 1].s;
		return word;
	}
};