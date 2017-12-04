#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-the-celebrity/description/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /*
     * Approach: Greedy.
     *
     * 1. if A knows B, then A is not celebrity, B might be celebrity.
     * 2. if A doesn't know B, then B is not celebrity, A might be celebrity.
     *
     *
     */
    int findCelebrity(int n) {
        int celebrity = 0;
        for(int i = 1; i < n; ++i)
            if(knows(celebrity, i)) celebrity = i;
        bool hasCelebrity = true;
        for(int i = 0; i < n; ++i)
            if(i != celebrity && (!knows(i, celebrity) || knows(celebrity, i))) hasCelebrity = false;
        return hasCelebrity ? celebrity : -1;
    }
};


int main() {

    Solution s;
    cout << s.findCelebrity(10) << endl;
    return 0;
}