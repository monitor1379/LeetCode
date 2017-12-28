#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else if (l1->val >= l2->val) {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }
};

int main() {
    ListNode *root1 = new ListNode(1);
    root1->next = new ListNode(2);
    root1->next->next = new ListNode(4);
    display_ListNode(root1);

    ListNode *root2 = new ListNode(1);
    root2->next = new ListNode(3);
    root2->next->next = new ListNode(4);
    display_ListNode(root2);

    Solution s;
    ListNode *root3 = s.mergeTwoLists(root1, root2);
    display_ListNode(root3);

    return 0;
}