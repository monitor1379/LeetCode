#include <iostream>

using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1), *p = head;
        int c = 0;
        while (l1 || l2) {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            p->next = new ListNode(c % 10);
            c /= 10;
            p = p->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (c) p->next = new ListNode(c);
        return head->next;
    }
};

int main() {
    ListNode *p1 = new ListNode(2);
    p1->next = new ListNode(4);
    p1->next->next = new ListNode(3);


    ListNode *p2 = new ListNode(5);
    p2->next = new ListNode(6);
    p2->next->next = new ListNode(4);

    Solution s;
    ListNode *node = s.addTwoNumbers(p1, p2);
    display_ListNode(node);

    return 0;
}