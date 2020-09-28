#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<char, set<string> > idx;
        for(char a = 'a';a<='z';++a){
            set<string> sset;
            idx[a] = sset;
        }
        for(int i=0;i<wordDict.size();++i){
            idx[wordDict[i][0]].insert(wordDict[i]);
        }
        string k = "";
        int i =0;
        while(i<s.size()&& k!= s){
            string word = "";
            int tag = 0;
            for(int j = 1;j<= s.size() - i;++j){
                string tmp = s.substr(i, j);
                if(idx[s[i]].find(tmp) != idx[s[i]].end()){
                    tag = 1;
                    word = tag;
                }
                else break;
            }
            if(tag) k+=word;
            else return false;
        }
        return true;
    }
};