#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool func(string a, int tag){ //tag = 1 代表整数  tag = 0 代表小数
        string b= a;
        if(tag == 1){
           while(a.size()>0&&a[0]=='0') a.erase(0, 1);
           //while(a.size()>0&&a[a.size()-1]=='0') a.erase(a.size()-1, 1);
            if(a == b) return true;
            else return false;
        }
        else {
            while(a.size()>0&&a[0] =='0'){
                a.erase(0, 1);
                if(a.size()>0&&a[0]=='.'){
                    a.insert(0, 1, '0');
                    break;
                }
            }
            while(a.size()>0&&a[a.size()-1]=='0') a.erase(a.size()-1, 1);
            if(a == b) return true;
            else return false;
        }
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for(int i =1;i<S.size();++i){
            string s = S, a, b, c, d;
            a = s.substr(0, i);
            b = s.substr(i, s.size()- i);
            if(func(a, 1) && func(b, 1)) res.push_back("("+a+", "+b+")");
            for(int j = 1;j<=a.size();++j){
                for(int k = 1;k<=b.size();++j){
                    c = a;
                    c.insert(j , 1, '.');
                    d = b;
                    d.insert(k , 1, '.');
                    if(func(c, 1) && func(d, 1)) res.push_back("("+c+", "+d+")");
                }
            }
        }
        return res;
    }
};