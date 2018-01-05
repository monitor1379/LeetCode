#include <iostream>

using namespace std;

// https://leetcode.com/problems/sort-list/description/

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

class Solution2 {
public:
    /*
     * Approach: Merge sort(recursion).
     *
     * Easy understand but not optimal solution.
     *
     * Time complexity:  O(nlogn)
     * Space complexity: O(n) stack place via recursion
     */
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p1 = head, *p2 = head, *pre = head;
        while (p2 && p2->next) {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }

        pre->next = nullptr;

        ListNode *p3 = sortList(head);
        ListNode *p4 = sortList(p1);

        return merge(p3, p4);
    }

    ListNode *merge(ListNode *p1, ListNode *p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val < p2->val) {
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

};


class Solution {
public:
    /*
     * Approach: Merge sort(not recursion).
     *
     *
     * Time complexity:  O(nlogn)
     * Space complexity: strict O(1)
     */
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        int length = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            length++;
        }

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *tail, *right, *left;

        for (int step = 1; step < length; step <<= 1) {
            cur = dummyHead->next;
            tail = dummyHead;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummyHead->next;
    }

    ListNode *split(ListNode *head, int n) {
        for (int i = 1; head && i < n; ++i) head = head->next;
        if (!head) return nullptr;
        ListNode *secondHead = head->next;
        head->next = nullptr;
        return secondHead;
    }

    // 合并并排序p1与p2，然后将合并后的链表拼在head的后面，返回指向新链表的最后一个节点的指针
    ListNode *merge(ListNode *p1, ListNode *p2, ListNode *head) {
        ListNode *cur = head;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
            } else {
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
        }
        cur->next = p1 ? p1 : p2;
        while (cur->next) cur = cur->next;
        return cur;
    }

};


int main() {
    ListNode *p1 = new ListNode(2);
    p1->next = new ListNode(4);
    p1->next->next = new ListNode(3);
    p1->next->next->next = new ListNode(1);
    p1->next->next->next->next = new ListNode(5);
    p1->next->next->next->next->next = new ListNode(6);

    Solution s;
    ListNode *result = s.sortList(p1);
    display_ListNode(result);

    return 0;
}