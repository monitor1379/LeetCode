#include <iostream>

using namespace std;

// https://leetcode.com/problems/insertion-sort-list/description/

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
    ListNode *insertionSortList(ListNode *head) {
        bool isSorted;
        for (ListNode *p1 = head; p1; p1 = p1->next) {
            ListNode *minP = p1;
            isSorted = true;
            for (ListNode *p2 = p1; p2; p2 = p2->next) {
                if (p2->val < minP->val)
                    minP = p2;
                if (p2->next && p2->val > p2->next->val)
                    isSorted = false;
            }
            if (isSorted) break;
            swap(p1->val, minP->val);
        }
        return head;
    }

    ListNode *insertionSortList2(ListNode *head) {
        if (!head) return nullptr;
        ListNode *dummyHead1 = new ListNode(-1);
        ListNode *dummyHead2 = new ListNode(-1);
        dummyHead1->next = head;
        ListNode *prev, *minPrev, *tail = dummyHead2;
        while (dummyHead1->next) {
            minPrev = dummyHead1;
            for (prev = dummyHead1; prev->next != nullptr; prev = prev->next)
                if (prev->next->val < minPrev->next->val)
                    minPrev = prev;
            tail->next = minPrev->next;
            tail = tail->next;
            minPrev->next = minPrev->next->next;
        }
        return dummyHead2->next;
    }
};


int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(3);
    display_ListNode(head);

    Solution s;
    head = s.insertionSortList(head);

    display_ListNode(head);
    return 0;
}