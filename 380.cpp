#include<cstdio>
#include<ctime>
#include<set>
#include<iostream>
using namespace std;
class RandomizedSet {
public:
    set<int> sset;
    /** Initialize your data structure here. */
    RandomizedSet() {
        sset.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(sset.find(val) != sset.end()) return false;
        sset.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(sset.find(val) != sset.end()){
            sset.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % sset.size();
		int cnt = 0;
		auto it = sset.begin();
		while (cnt < r) {
			++cnt, ++it;
		}
		return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(){
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(0) << endl;
    cout << obj->insert(1) << endl;
    cout << obj->remove(0) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->remove(1) << endl;
    cout << obj->getRandom() << endl;
    return 0;
}