#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        int left, right;
        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) {
                left = intervals[i].start;
                right = intervals[i].end;
            } else if (intervals[i].start <= right) {
                right = max(right, intervals[i].end);
            } else {
                Interval interval(left, right);
                res.push_back(interval);
                left = intervals[i].start;
                right = intervals[i].end;
            }
        }
        Interval interval(left, right);
        res.push_back(interval);
        return res;
    }
};
