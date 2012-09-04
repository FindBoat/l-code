#include<queue>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class PairComparator {
public:
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        ListNode *head = NULL;
        ListNode *cur = NULL;
        priority_queue<pair<int, int>, vector<pair<int, int> >, PairComparator> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i]) continue;
            heap.push(pair<int, int>(lists[i]->val, i));
            lists[i] = lists[i]->next;
        }
        while (!heap.empty()) {
            pair<int, int> p = heap.top();
            heap.pop();
            ListNode *node = new ListNode(p.first);
            if (!head) {
                head = node;
                cur = head;
            } else {
                cur->next = node;
                cur = cur->next;
            }
            if (lists[p.second]) {
                heap.push(pair<int, int>(lists[p.second]->val, p.second));
                lists[p.second] = lists[p.second]->next;
            }
        }
        return head;
    }
};
