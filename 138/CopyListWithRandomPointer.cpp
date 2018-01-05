#include <iostream>
#include <map>

using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/description/

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void display_RandomListNode(RandomListNode *head) {
    for (RandomListNode *p = head; p != nullptr; p = p->next) {
        cout << p << "(" << p->label << ", ";
        if (p->random)
            cout << p->random << "(" << p->random->label << ")" << "), ";
        else
            cout << "null), ";
    }
    cout << endl;
}


class Solution {
public:
    /*
     * Approach: Hash table.
     *
     * 如果正常的链表，要拷贝就容易：从左往右访问，遇到一个节点，就产生一个新节点放在新链表尾部。
     * 这道题的链表就不“正常”，每个节点还可能指向前面已经生成的节点或后面还没产生的节点。
     *
     * 如果第一遍先不管random指针，先按照正常链表产生；然后再处理random指针。
     * 问题是：旧链表之间的random指针如何复制到新链表中去？
     * 这个方法，把新旧链表完全独立开来，旧链表的random指针就无法复制到新链表了。
     *
     * Time complexity:  O(n)
     * Space complexity: O(n)
     *
     */
    RandomListNode *copyRandomList2(RandomListNode *head) {
        if (!head) return nullptr;
        map<RandomListNode *, RandomListNode *> m;
        RandomListNode *p = head, *prev = nullptr;
        while (p) {
            if (m.find(p) == m.end()) {
                m[p] = new RandomListNode(p->label);
                if (!prev) {
                    prev = m[p];
                } else {
                    prev->next = m[p];
                    prev = prev->next;
                }
            }
            p = p->next;
        }

        p = head;
        while (p) {
            if (p->random)
                m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }

    /*
     * Approach: 脚手架
     *
     * Time complexity:  O(n)
     * Space complexity: O(1)
     *
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;

        // 1. 搭建脚手架
        RandomListNode *cur = head, *next;
        while (cur) {
            next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = next;
        }

        // 2. 复制random指针
        cur = head;
        while (cur) {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }

        // 3. 拆开脚手架
        RandomListNode *newHead = head->next;
        while (head) {
            cur = head->next;
            head->next = cur->next;
            cur->next = cur->next ? cur->next->next : nullptr;
            head = head->next;
        }
        return newHead;
    }
};


int main() {
    RandomListNode *head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = new RandomListNode(4);
    head->next->next->next->next = new RandomListNode(5);
    head->random = head->next->next;
    head->next->next->next->next->random = head->next;
    display_RandomListNode(head);

    Solution s;
    RandomListNode *p = s.copyRandomList(head);

    display_RandomListNode(head);
    display_RandomListNode(p);


    return 0;
}