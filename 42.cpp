#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int res = 0;
        if (height.size() <= 2) return 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int left = -1, right = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > left) left = height[j];
            }
            for (int j = i + 1; j < height.size(); j++) {
                if (height[j] > right) right = height[j];
            }
            if (height[i] < left && height[i] < right) res += min(left, right) - height[i];
        }
        return res;
    }
};