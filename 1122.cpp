#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> idx;
        for(int i=0;i<arr1.size();i++){
            if(idx.find(arr1[i]) == idx.end()) idx[arr1[i]] = 1;
            else idx[arr1[i]]++;
        }
        arr1.clear();
        for(int i=0;i<arr2.size();++i){
            arr1.insert(arr1.end(), idx[arr2[i]], arr2[i]);
            idx.erase(idx.find(arr2[i]));
        }
        for(auto elem : idx){
            arr1.insert(arr1.end(), elem.second, elem.first);
        }
        return arr1;
    }
};