#include <iostream>

using namespace std;

// https://leetcode.com/problems/linked-list-cycle/description/

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
     * Approach: Cycle Detection algorithm.
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     * 
     */
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast != nullptr && fast == slow;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next;


    Solution s;
    cout << s.hasCycle(head) << endl;

    return 0;
}