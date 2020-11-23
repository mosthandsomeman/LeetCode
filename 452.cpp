#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] != b[0]? a[0] <b[0]:a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 0;
        if(points.size() <= 1) return points.size();
        sort(points.begin(), points.end(), cmp);
        int p = points[0][1], q = points[0][1], i = 1;
        while(i<points.size()){
            int j = i;
            while(j< points.size() && !(q < points[j][0] || p > points[j][1])){
                j++;
                p = max(p, points[j][0]);
                q = min(q, points[j][1]);
            }
            if(j == points.size()) {
                cnt++;
                break;
            }
            cnt++;
            i = j;
            p = points[i][0], q = points[i][1];
        }
        return cnt;
    }
};