#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    /*
     * Approach: Recursive.
     *
     * hints:
     * 1. preorder[0]是当前的根节点值。
     * 2. 假设当前根节点的值在inorder的下标是i，则：
     *      在inorder[i]左边的是当前根节点的左子树的中序遍历；
     *      在inorder[i]右边的是当前根节点的右子树的中序遍历。
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode *root = buildTreeImpl(preorder, 0, preorder.size() - 1,
                                       inorder, 0, inorder.size() - 1);
        return root;
    }

    TreeNode *buildTreeImpl(vector<int> &preorder, int s1, int e1,
                            vector<int> &inorder, int s2, int e2) {
        // 由于默认调用该函数时必然构建根节点，因此无需再次判断，直接创建
        auto *root = new TreeNode(preorder[s1]);

        int i;
        for (i = s2; i <= e2 && inorder[i] != root->val; ++i); //寻找当前根节点在inorder中的下标

        // 判断是否构建左子树
        int left_len = i - s2;
        if (left_len > 0)
            root->left = buildTreeImpl(preorder, s1 + 1, s1 + left_len,
                                       inorder, s2, s2 + left_len - 1);



        // 判断是否构建右子树
        int right_len = e2 - i;
        if (right_len > 0)
            root->right = buildTreeImpl(preorder, s1 + left_len + 1, s1 + left_len + right_len,
                                        inorder, i + 1, i + right_len);
        return root;
    }
};

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 8, 7};
    vector<int> inorder = {4, 2, 5, 1, 8, 6, 3, 7};

//    vector<int> preorder = {};
//    vector<int> inorder = {};

    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    display_tree(root, 0);

    return 0;
}