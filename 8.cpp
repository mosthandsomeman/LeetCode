#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int i = 0, tag = -1, flag = -1, j = 0;
		string ss;
		while (i < str.size()) {
			if (str[i] == ' ') {
				++i;
			}
			else if (str[i] == '-'|| str[i] == '+') {
				tag = 1;
				break;
			}
			else if (str[i] >= '0'&&str[i] <= '9') {
				tag = 2;
				break;
			}
			else {
				tag = 0;
				break;
			}
		}
		if (tag < 1) return 0;
		if (tag == 1) {
			if (str[i] == '-') {
				flag = 1;
				++i;
			}
			else if (str[i] == '+') {
				flag = 2;
				++i;
			}
		}
		j = i;
		while (j < str.size()) {
			if (str[j] >= '0'&&str[j] <= '9') ++j;
			else break;
		}
		ss = str.substr(i, j - i);
		if (ss.size() == 0) return 0;
		while (ss[0] == '0' && ss.size() > 1)  ss.erase(0, 1);
		if (ss.size() > 10) {
			if (flag == 1) return INT_MIN;
			else if (flag == 2) return INT_MAX;
		}
		long long a = atol(ss.c_str());
		if (flag == 1) a = -a;
		if (a > INT_MAX) return INT_MAX;
		if (a < INT_MIN) return INT_MIN;
		return a;
	}
};