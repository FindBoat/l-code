#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    // Algorithm: http://stackoverflow.com/questions/4311694/maximize-the-rectangular-area-under-histogram.
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> stack;
        for (int i = 0; i < height.size(); i++) {
            while (!stack.empty() && height[i] < height[stack.top()]) {
                   int h = height[stack.top()];
                   stack.pop();
                   int left = stack.empty() ? -1 : stack.top();
                   res = max(res, h * (i - left - 1));
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            int h = height[stack.top()];
            stack.pop();
            int left = stack.empty() ? -1 : stack.top();
            res = max(res, h * ((int) height.size() - left - 1));
        }
        return res;
    }
    
    int largestRectangleArea2(vector<int> &height) {
        int left[height.size()];
        int right[height.size()];
        vector<int> stack;
        for (int i = 0; i < height.size(); i++) {
            while (!stack.empty() && height[stack.back()] > height[i]) stack.pop_back();
            if (stack.empty()) {
                left[i] = -1;
            } else {
                left[i] = stack.back();
            }
            stack.push_back(i);
        }
        stack.clear();
        for (int i = height.size() - 1; i >= 0; i--) {
            while (!stack.empty() && height[stack.back()] > height[i]) stack.pop_back();
            if (stack.empty()) {
                right[i] = height.size();
            } else {
                right[i] = stack.back();
            }
            stack.push_back(i);
        }
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int start = left[i] + 1, end = right[i] - 1;
            res = max(res, height[i] * (end - start + 1));
        }
        return res;
    }
};
