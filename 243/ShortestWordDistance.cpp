#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// https://leetcode.com/problems/shortest-word-distance/description/

void display_vector(vector<string> v)
{
    for(string i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution
{
public:
    int shortestDistance(vector<string>& words, string word1, string word2)
    {

        int i = words.size(), j = words.size(), d = INT_MAX;
        for(int k = 0; k < words.size(); ++k)
        {
            if(words[k] == word1) i = k;
            if(words[k] == word2) j = k;
            if(i != words.size() && j != words.size()) d = min(d, abs(i - j));
        }
        return d;
    }
};

int main()
{
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
//    string word1 = "coding", word2 = "practice";
    string word1 = "makes", word2 = "coding";

    display_vector(words);

    Solution s;
    cout << s.shortestDistance(words, word1, word2) << endl;
    return 0;
}
