#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> res;
        sort(deck.begin(),deck.end());
        res.push_back(deck[deck.size()-1]);
        for(int i = deck.size()-2;i>=0;--i){
            res.insert(res.begin(), deck[i]);
            int val = *res.rbegin();
            res.pop_back();
            res.insert(res.begin()+1, val);
        }
        return res;
    }
};