#include "bits/stdc++.h"
using namespace std;
class RandomizedCollection
{
public:
    /** Initialize your data structure here. */
    multiset<int> data;
    
    RandomizedCollection()
    {
        data.clear();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        if (data.find(val) == data.end())
        {
            data.insert(val);
            return true;
        }
        else{
            data.insert(val);
            return false;
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (data.find(val) != data.end())
        {
            data.erase(val);
            return true;
        }
        else
            return false;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        //srand((unsigned)time(NULL));
        vector<int> vec(data.begin(), data.end());
        return vec[rand() % data.size()];
    }
};