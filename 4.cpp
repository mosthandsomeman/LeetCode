//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		double res = 0;
//		vector<int> vec;
//		for (int i = 0; i < nums1.size(); ++i) {
//			vec.push_back(nums1[i]);
//		}
//		for (int i = 0; i < nums2.size(); ++i) {
//			vec.push_back(nums2[i]);
//		}
//		sort(vec.begin(), vec.end());
//		if (vec.size() % 2 == 1) {
//			res = vec[vec.size() / 2];
//		}
//		else
//		{
//			 res = (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2.0;
//		}
//		return res;
//	}
//};