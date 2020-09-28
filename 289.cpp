#include <vector>
using namespace std;
int x[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int y[8] = {0, 0, -1, 1, -1, 1, -1, 1};
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int> > res = board;
        for (int i = 0; i < res.size();++i){
            for(int j =0;j<res[i].size();++j){
                int cnt = 0;
                for(int k =0;k<8;++k){
                    int idx = i + x[k], idy = j + y[k];
                    if(idx>=0&&idx<res.size()&&idy>=0&&idy<res[i].size()){
                        cnt += res[idx][idy];
                    }
                }
                if(!res[i][j]&&cnt ==3) board[i][j] = 1;
                else if(res[i][j]&&cnt < 2) board[i][j] = 0;
                else if(res[i][j]&&cnt > 3) board[i][j] = 0;
            }
        }
    }
};