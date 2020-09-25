#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int num)
    {
        string s(32, '0');
        int cnt = 0;
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= num; ++i)
        {
            if (s[0] == '0')
            {
                s[0] = '1';
                ++cnt;
                res.push_back(cnt);
            }
            else
            {
                s[0] = '0';
                --cnt;
                int jin = 1;
                for (int j = 1; j < 32; ++j)
                {
                    s[j] += jin;
                    if(s[j] == '1') {
                        ++cnt;
                        break;
                    } 
                    else {
                        s[j] = '0';
                        --cnt;
                    }
                }
                res.push_back(cnt);
            }
        }
        return res;
    }
};