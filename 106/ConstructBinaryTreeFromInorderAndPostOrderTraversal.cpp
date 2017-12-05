#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildNode(inorder, 0, inorder.size() -1, postorder, 0, postorder.size() - 1);
    }

    TreeNode *buildNode(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2) {
        if(s1 > e1) return nullptr;
        else if(s1 == e1) {
            return new TreeNode(inorder[s1]);
        } else {
            TreeNode *node = new TreeNode(postorder[e2]);
            int i2 = e2;
            int i1;
            for(i1 = s1; i1 <= e1 && inorder[i1] != postorder[i2]; ++i1);
            int left_len = i1 - s1;
            node->left = buildNode(inorder, s1, i1 - 1, postorder, s2, s2 + left_len - 1);
            node->right = buildNode(inorder, i1 + 1, e1, postorder, s2 + left_len, e2 - 1);
            return node;
        }
    }
};

int main() {
    vector<int> inorder =   {4, 2, 5, 1, 6, 7, 3};
    vector<int> postorder = {4, 5, 2, 7, 6, 3, 1};
    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);
    display_tree(root, 0);
    return 0;
}