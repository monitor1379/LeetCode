#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/shortest-word-distance-iii/description/

class Solution {
public:
    /*
     * Time complexity:  O(n)
     * Space complexity: O(1)
     * 
     */
    int shortestWordDistance(vector<string> &words, string word1, string word2) {
        int i = -words.size(), j = words.size();
        int d = words.size();
        bool same = word1 == word2;
        for (int k = 0; k < words.size(); ++k) {
            if (words[k] == word1) {
                i = k;
                if (same)
                    swap(i, j);
            } else if (words[k] == word2)
                j = k;
            d = min(d, abs(j - i));
        }
        return d;
    }
};

int main() {
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};

    Solution s;
    cout << s.shortestDistance(words, "makes", "coding") << endl;
    cout << s.shortestDistance(words, "makes", "makes") << endl;
    return 0;
}