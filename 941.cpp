#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool res = true, tag = true;
        if(A.size() < 3) return false;
        int i = 0, j = A.size() - 1;
        while(i < A.size() - 1 && A[i] < A[i + 1]) ++i;
        while(j> 0 && A[j] < A[j - 1]) --j;
        if(i == 0 || j == A.size() - 1) return false;
        return i == j;
    }
};