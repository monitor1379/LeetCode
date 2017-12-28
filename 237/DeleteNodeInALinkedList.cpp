#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void display_ListNode(ListNode *head) {
    for (ListNode *p = head; p != nullptr; p = p->next)
        cout << p->val << ", ";
    cout << endl;
}

class Solution {
public:
    void deleteNode(ListNode *node) {
        if (node && node->next) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};

int main() {
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    display_ListNode(root);

    Solution s;
    s.deleteNode(root->next->next);
    display_ListNode(root);


    return 0;
}