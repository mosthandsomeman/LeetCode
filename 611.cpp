#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Solution
{
public:
	int triangleNumber(vector<int> &nums)
	{
		int res = 0, a = 0;
		int *c = new int[1001];
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			if (nums[i] == 0) continue;
			if (i > 0 && nums[i] == nums[i - 1]) {
				for (int t = i + 1; t < nums.size(); ++t) {
					res += c[t];
				}
				continue;
			}
			a = 0;
			fill(c, c + 1001, 0);
			for (int j = i + 1; j < nums.size() - 1; ++j)
			{
				if (nums[j] == 0) continue;
				for (int k = j + 1; k < nums.size(); ++k)
				{
					if (nums[k] == 0) continue;
					if (nums[i] + nums[j] > nums[k]) {
						a++;
						c[j]++;
					}
				}
			}
			res += a;
		}
		return res;
	}
};