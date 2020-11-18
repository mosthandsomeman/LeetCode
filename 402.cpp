#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        int cnt = k, i = 0;
        for (int i = 0; i < num.size(); i++) {
            while (s.size() > 0 && num[i] < *s.rbegin() && cnt > 0) {
                cnt--;
                s.pop_back();
            }
            s.push_back(num[i]);
        }
        while (cnt > 0) {
            s.pop_back();
            cnt--;
        }
        num = string(s.begin(), s.end());
        while (num.size() > 0 && num[i] == '0') {
            num.erase(0, 1);
        }
        return num.size() == 0 ? "0" : num;
    }
};