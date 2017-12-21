#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/construct-string-from-binary-tree/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


template<typename T>
string toString(T num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

class Solution {
public:
    string tree2str(TreeNode *t) {
        return backtrack(t);
    }


    string backtrack(TreeNode *t) {
        if (t == nullptr) return "";
        else {
            string s;
            s += toString(t->val);

            if (t->left)
                s += "(" + backtrack(t->left) + ")";
            if (t->right) {
                if (!t->left)
                    s += "()";
                s += "(" + backtrack(t->right) + ")";
            }
            return s;
        }
    }
};

int main() {
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);

    TreeNode *root3 = new TreeNode(-1);
    root3->left = new TreeNode(-2);
    root3->right = new TreeNode(-3);
    root3->left->left = new TreeNode(-4);

    Solution s;
    cout << s.tree2str(root1) << endl;
    cout << s.tree2str(root2) << endl;
    cout << s.tree2str(root3) << endl;

    return 0;
}