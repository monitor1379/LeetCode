#include <iostream>
#include <vector>
#include <map>
#include <random>

using namespace std;

// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

/*
 * Approach: Using map and vector.
 *
 * 使用map来实现O(1)的insert与remove，
 * 使用vector来实现getRandom()。
 * 
 */
class RandomizedSet {
private:
    map<int, int> m;
    vector<int> v;
    default_random_engine rand;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool contain = m.find(val) != m.end();
        if (!contain) {
            m[val] = v.size();
            v.push_back(val);
        }
        return !contain;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool contain = m.find(val) != m.end();
        if(contain) {
            int i = m[val];
            if(i != v.size() - 1) {
                swap(v[i], v[v.size() - 1]);
                m[v[i]] = i;
            }
            m.erase(val);
            v.erase(--v.end());
        }
        return contain;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    RandomizedSet rs;
    cout << "insert 1: " << rs.insert(1) << endl;
    cout << "insert 3: " << rs.insert(3) << endl;
    cout << "insert 4: " << rs.insert(4) << endl;
    cout << "insert 3: " << rs.insert(3) << endl;
    for(int i = 0; i < 100; i++)
        cout << rs.getRandom() << " ";
    cout << endl;

    return 0;
}