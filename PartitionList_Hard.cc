#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *h = NULL;
        ListNode *cur = NULL;
        ListNode *h2 = NULL;
        ListNode *cur2 = NULL;
        while (head) {
            if (head->val < x) {
                if (!h) {
                    h = head;
                    cur = head;
                } else {
                    cur->next = head;
                    cur = head;
                }
            } else {
                if (!h2) {
                    h2 = head;
                    cur2 = head;
                } else {
                    cur2->next = head;
                    cur2 = head;
                }
            }
            head = head->next;
        }
        if (cur) cur->next = h2;
        cur2->next = NULL;
        return h ? h : h2;
    }
};
int main() {
    Solution s;
    ListNode *p0 = new ListNode(1);
    ListNode *p1 = new ListNode(4);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(2);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(2);
    p0->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    ListNode *res = s.partition(p0, 3);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
}
