#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/word-search/description/

template<typename T>
void display_2d_vector(vector<vector<T>> &v) {
    for (vector<T> vi: v) {
        for (T i: vi)
            cout << i << ", ";
        cout << endl;
    }
}

class Solution {
public:
    // Approach: depth-first search.
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() or board[0].empty()) return false;
        int R = board.size(), C = board[0].size();
        vector<vector<int>> seen(R, vector<int>(C, 0));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                clear(seen);
                if (search_word(board, word, 0, seen, i, j)) return true;
            }
        }
        return false;
    }

    bool search_word(vector<vector<char>> &board, string &word, int k, vector<vector<int>> &seen, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || seen[i][j] == 1 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1) return true;
        else {
            seen[i][j] = 1;
            bool found = search_word(board, word, k + 1, seen, i - 1, j) ||
                          search_word(board, word, k + 1, seen, i + 1, j) ||
                          search_word(board, word, k + 1, seen, i, j - 1) ||
                          search_word(board, word, k + 1, seen, i, j + 1);
            if(!found) seen[i][j] = 0;
            return found;
        }

    }

    void clear(vector<vector<int>> v) {
        for (int i = 0; i < v.size(); ++i)
            for (int j = 0; j < v[0].size(); ++j)
                v[i][j] = 0;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};

//    vector<vector<char>> board = {{'C', 'C', 'A'},
//                                  {'A', 'A', 'A'},
//                                  {'B', 'C', 'D'}};
    display_2d_vector(board);

    Solution s;
    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;
    cout << s.exist(board, "AAB") << endl;
    return 0;
}