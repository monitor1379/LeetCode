#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/longest-univalue-path/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void display_tree(TreeNode *root, int k) {
    if (root) {
        for (int i = 0; i < k; ++i) cout << "   ";
        cout << "|--" << root->val << endl;
        display_tree(root->left, k + 1);
        display_tree(root->right, k + 1);
    }
}

class Solution {

public:
    int maxCnt = 0;

    int longestUnivaluePath(TreeNode *root) {
        maxCnt = 0;
        backtrack(root);
        return maxCnt;
    }

    int backtrack(TreeNode *node) {
        if (!node) return 0;

        int leftLUP = backtrack(node->left);  // 表示左子节点的LUP
        int rightLUP = backtrack(node->right);  // 表示右子节点的LUP
        int curToLeftLUP = 0;  // 表示当前节点往左子节点走的LUP
        int curToRightLUP = 0;  // 表示当前节点往右子节点走的LUP

        if (node->left && node->left->val == node->val)
            curToLeftLUP = leftLUP + 1;
        if (node->right && node->right->val == node->val)
            curToRightLUP = rightLUP + 1;

        // 表示左子节点经过当前节点往右子节点走的LUP
        // 如果其中一个子节点不通，则表示当前节点往可走通节点的LUP
        int leftToRightLUP = curToLeftLUP + curToRightLUP;
        maxCnt = max(maxCnt, leftToRightLUP);

        return max(curToLeftLUP, curToRightLUP);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    display_tree(root, 0);

    Solution s;
    cout << s.longestUnivaluePath(root) << endl;
    return 0;
}