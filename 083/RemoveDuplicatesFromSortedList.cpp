#include <iostream>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p2 != nullptr) {
            while (p2 && p1->val == p2->val) p2 = p2->next;
            p1->next = p2;
            p1 = p2;
        }
        return head;
    }
};

int main() {
    ListNode *p1 = new ListNode(1);
    p1->next = new ListNode(1);
//    p1->next->next = new ListNode(2);
//    p1->next->next->next = new ListNode(2);
//    p1->next->next->next->next = new ListNode(2);

    Solution s;
    ListNode *node = s.deleteDuplicates(p1);
    display_ListNode(node);

    return 0;
}