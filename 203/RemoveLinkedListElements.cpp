#include <iostream>

using namespace std;

// https://leetcode.com/problems/remove-linked-list-elements/description/

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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            if (cur->val == val) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
            } else
                prev = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main() {
    ListNode *p1 = new ListNode(1);
    p1->next = new ListNode(2);
    p1->next->next = new ListNode(3);
    p1->next->next->next = new ListNode(2);
    p1->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *node = s.removeElements(p1, 2);
    display_ListNode(node);

    return 0;
}