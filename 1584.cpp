#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 1001
#define INF 1000000000
class Solution
{
public:
    int G[MAX][MAX] = {0}, d[MAX];
    bool vis[MAX] = {false};
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                int val = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                G[i][j] = G[j][i] = val;
            }
        }
        int cost = 0;
        fill(d, d + MAX, INF);
        fill(vis, vis + MAX, false);
        d[0] = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int u = -1, MIN = INF;
            for (int j = 0; j < points.size(); ++j)
            {
                if (vis[j] == false && d[j] < MIN)
                {
                    u = j;
                    MIN = d[j];
                }
            }
            vis[u] = true;
            cost += d[u];
            for (int v = 0; v < points.size(); ++v)
            {
                if (vis[v] == false && G[u][v] < d[v])
                {
                    d[v] =  G[u][v];
                }
            }
        }
        return cost;
    }
};