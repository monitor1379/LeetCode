#include <iostream>

using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        // 1. find the middle node.
        // example1:  1->2->3, middle node: 2
        // example2:  1->2->3->4, middle node: 2
        ListNode *p = findMiddleListNode(head);

        // 2. reverse right part.
        p->next = reverseListNode(p->next);
        p = p->next;

        // 3. compare left part and right part.
        while (p) {
            if (head->val != p->val)
                return false;
            head = head->next;
            p = p->next;
        }
        return true;
    }

    ListNode *findMiddleListNode(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseListNode(ListNode *head) {
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
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);


    Solution s;
    cout << s.isPalindrome(head) << endl;

    return 0;
}