#include<iostream>
using namspace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        bool carry = false;
        while (l1 || l2) {
            int t1 = l1 ? l1->val : 0;
            int t2 = l2 ? l2->val : 0;
            int tmp = t1 + t2;
            if (carry) tmp++;
            if (tmp > 9) {
                tmp -= 10;
                carry = true;
            }
            ListNode *node = new ListNode(tmp);
            if (!cur) {
                head = node;
            } else {
                cur->next = node;
            }
            cur = node;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (carry) cur->next = new ListNode(1);
        return head;
    }
};
