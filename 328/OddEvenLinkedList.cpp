#include <iostream>

using namespace std;

// https://leetcode.com/problems/odd-even-linked-list/description/

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
    /*
     * Approach: 拆分脚手架
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     *
     */
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *newHead = head->next, *p1 = head, *p2, *prev = p1;
        while (p1) {
            prev = p1;
            if (!p1->next) break;
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p2->next ? p2->next->next : nullptr;
            p1 = p1->next;
        }
        prev->next = newHead;
        return head;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    s.oddEvenList(head);

    display_ListNode(head);
    return 0;
}