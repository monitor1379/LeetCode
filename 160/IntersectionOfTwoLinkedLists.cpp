#include <iostream>
#include <map>

using namespace std;

// https://leetcode.com/problems/intersection-of-two-linked-lists/solution/

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
     * Request:
     * 1. There are no cycles anywhere in the entire linked structure.
     * 2. The linked lists must retain their original structure after the function returns.
     * 3. O(n) time and O(1) space.
     *
     * Approach: Two pointers.
     *
     *
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }

    /*
     * Approach: Hash table.
     *
     * Time complexity:  O(len(A) + len(B))
     * Space complexity: O(len(A))
     */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        map<ListNode *, int> m;
        for (ListNode *p = headA; p != nullptr; p = p->next) m[p] = 1;
        for (ListNode *p = headB; p != nullptr; p = p->next)
            if (m[p] == 1)return p;
        return nullptr;
    }
};


int main() {
    ListNode *p1 = new ListNode(1);
    p1->next = new ListNode(2);
    p1->next->next = new ListNode(3);
    p1->next->next->next = new ListNode(4);
    p1->next->next->next->next = new ListNode(5);


    ListNode *p2 = new ListNode(1);
    p2->next = new ListNode(2);
    p2->next->next = new ListNode(3);
    p2->next->next->next = p1->next->next;


    Solution s;
    ListNode *node = s.getIntersectionNode(p1, p2);
    if (node)
        cout << node->val << endl;
    else
        cout << "null" << endl;

    return 0;
}