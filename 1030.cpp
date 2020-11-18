#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    int X[4] = {-1, 1, 0, 0,};
    int Y[4] = {0, 0, -1, 1};
    bool judge(int R, int C, int i, int j)
    {
        if (i >= 0 && i < R && j >= 0 && j < C)
            return true;
        else
            return false;
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> idx;
        q.push(pair<int, int>(r0, c0));
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            idx[pair<int, int>(top.first, top.second)] = true;
            for(int i =0;i<4;++i){
                int x1 = X[i] + top.first;
                int y1 = Y[i] + top.second;
                if(judge(R, C, x1, y1) && idx.find(pair<int, int>(x1, y1)) == idx.end()){
                    q.push(pair<int, int>(x1, y1));
                }
            }
        }
        return res;
    }
};