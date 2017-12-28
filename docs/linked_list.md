# 寻找链表的中间结点

```c++

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* findMiddleNode(ListNode *head) {
    if(!head) return nullptr;
    ListNode *slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```
