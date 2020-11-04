#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		vector<vector<int>> res;
		if (intervals.size() == 0) {
			res.push_back(newInterval);
			return res;
		}
		int tag = 0;
		for (int i = 0; i < intervals.size(); ++i)
		{
			if (tag) {
				res.push_back(intervals[i]);
				continue;
			}
			if (newInterval[0] > intervals[i][1])
				res.push_back(intervals[i]);
			else
			{
				vector<int> tmp;
				if (newInterval[0] <= intervals[i][0])
					tmp.push_back(newInterval[0]);
				else
					tmp.push_back(intervals[i][0]);

				if (newInterval[1] < intervals[i][0]) {
					tmp.push_back(newInterval[1]);
					res.push_back(tmp);
                    res.push_back(intervals[i]);
					tag = 1;
				}
				else if (newInterval[1] <= intervals[i][1])
				{
					tmp.push_back(intervals[i][1]);
					res.push_back(tmp);
					tag = 1;
				}
				else
				{
					int j = i + 1;
					while (j < intervals.size())
					{
						if (intervals[j][1] < newInterval[1]) ++j;
						else {
							if (intervals[j][0] <= newInterval[1]) {
								tmp.push_back(intervals[j][1]);
								break;
							}
							else {
								tmp.push_back(newInterval[1]);
								break;
							}
						}
					}
					if (j == intervals.size()) {
						tmp.push_back(newInterval[1]);
						res.push_back(tmp);
						tag = 1;
						break;
					}
					else {
						if (tmp[1] < intervals[j][0]) i = j - 1;
						else i = j;
						res.push_back(tmp);
						tag = 1;
					}
				}
			}
		}
		return res;
	}
};