#include <iostream>

using namespace std;

// https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *cur = head, *next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);


    Solution s;
    ListNode *head2 = s.reverseList(head);
    display_ListNode(head2);

    return 0;
}