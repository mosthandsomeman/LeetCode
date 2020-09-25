#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<int> & tmp, vector<vector<int> > & res ,int k, int idx, int n){
        tmp.push_back(idx);
        if(tmp.size() == k){
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        for(int i = idx + 1;i<=n;++i){
            dfs(tmp, res, k,i,n);
        }
        tmp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        for(int i = 1;i<=n;++i){
            tmp.clear();
            dfs(tmp, res, k,i,n);
        }
        return res;
    }
};