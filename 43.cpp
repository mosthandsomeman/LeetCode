#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 =="0" || num2 == "0") return "0";
        if(num1.size() > num2.size()) swap(num1, num2);
        vector<string> vec;
        for(int i=0;i<num1.size();++i){
            string tmp = "";
            tmp.insert(0, i, '0');
            int jin = 0;
            if(num1[i] != '0'){
                for(int j = 0;j<num2.size();++j){
                    int t = jin + (num1[i] - '0') * (num2[j] - '0');
                    tmp.insert(0, 1, t % 10 + '0');
                    jin = t / 10;
                }
                if(jin != 0) tmp.insert(0, 1, jin + '0');
                vec.push_back(tmp);
            }
        }
        if(vec.size() == 1) return vec[0];
        for(int i=1;i<vec.size();++i){
            string s = "";
            int jin = 0;
            int j = vec[0].size() -1 , t = vec[i].size() - 1;
            for(;j >=0 && t>=0;j--, t--){
                int sum = vec[0][j] - '0' + jin + vec[i][t] - '0';
                s.insert(0, 1, sum % 10 + '0');
                jin = sum / 10;
            }
            while(j >= 0){
                int sum = vec[0][j] - '0' + jin;
                s.insert(0, 1, sum % 10 + '0');
                jin = sum / 10;
                --j;
            }
            while(t >= 0){
                int sum = vec[0][t] - '0' + jin;
                s.insert(0, 1, sum % 10 + '0');
                jin = sum / 10;
                --t;
            }
            if(jin != 0) s.insert(0, 1, jin + '0');
        }
        return vec[0];
    }
};