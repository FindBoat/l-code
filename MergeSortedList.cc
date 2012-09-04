#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void swap(ListNode *&l1, ListNode *&l2) {
        ListNode *tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 && p2) {
            if (p1->val > p2->val) swap(p1, p2);
            if (!head) {
                head = p1;
                cur = p1;
            } else {
                cur->next = p1;
                cur = cur->next;
            }
            p1 = p1->next;
        }
        if (!p1) swap(p1, p2);
        while (p1) {
            if (!head) {
                head = p1;
                cur = p1;
            } else {
                cur->next = p1;
                cur = cur->next;
            }
            p1 = p1->next;
        }
        return head;
    }
};
