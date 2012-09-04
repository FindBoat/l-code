#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval new_interval) {
        vector<Interval> res;
        int left = -1, right = -1;
        bool inserted = false;
        intervals.push_back(new_interval);
        for (int i = 0; i < intervals.size(); i++) {
            if (i == intervals.size() - 1 && inserted) break;
            Interval cur = intervals[i];
            if (!inserted && intervals[i].start > new_interval.start) {
                inserted = true;
                cur = new_interval;
                i--;
            }
            if (left == -1) {
                left = cur.start;
                right = cur.end;
            } else if (cur.start <= right) {
                right = max(right, cur.end);
            } else {
                Interval interval(left, right);
                res.push_back(interval);
                left = cur.start;
                right = cur.end;
            }
        }
        Interval interval(left, right);
        res.push_back(interval);
        return res;
    }
};
