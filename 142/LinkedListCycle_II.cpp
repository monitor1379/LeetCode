#include <iostream>
#include <map>

using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/description/

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
     * Approach: Floyd's Tortoise and Hare.
     *
     * https://leetcode.com/problems/linked-list-cycle-ii/solution/
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     *
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }


    /*
     * Approach: Hash Table.
     *
     * Time complexity:  O(n)
     * Space complexity: O(n)
     *
     */
    ListNode *detectCycle2(ListNode *head) {
        if (!head) return nullptr;
        map<ListNode *, int> m;
        for (ListNode *p = head; p; p = p->next) {
            ++m[p];
            if (m[p] == 2)
                return p;
        }
        return nullptr;
    }
};


int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next = head->next->next;

    Solution s;
    ListNode *p = s.detectCycle(head);
    cout << p->val << endl;

    return 0;
}