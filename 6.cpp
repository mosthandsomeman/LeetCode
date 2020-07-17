//#include<string>
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (numRows == 1) return s;
//		string * str = new string[numRows];
//		int j = 0, tag = 0; // 0 正向   1  反向
//		for (int i = 0; i < s.size(); ++i) {
//			str[j].insert(str[j].size(), 1, s[i]);
//			if (!tag) {
//				if (j == numRows - 1) {
//					--j;
//					tag = 1;
//				}
//				else {
//					++j;
//				}
//			}
//			else {
//				if (j == 0) {
//					++j;
//					tag = 0;
//				}
//				else {
//					--j;
//				}
//			}
//		}
//		string res = "";
//		for (int i = 0; i < numRows; ++i) {
//			res += str[i];
//		}
//		return res;
//	}
//};