#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, cur_sum = 0, cur_length = 0;
        // Every time when the cur_sum < 0, the next start point can only be the right of
        // the last ')'. The only exception is when it comes to the end, like "(()", and this
        // can be solved by the reverse operation.
        for (int i = 0; i < s.length(); i++) {
            cur_length++;
            if (s[i] == '(') {
                cur_sum++;
            } else {
                cur_sum--;
            }
            if (cur_sum == 0) {
                res = max(res, cur_length);
            } else if (cur_sum < 0) {
                cur_sum = 0;
                cur_length = 0;
            }
        }
        cur_sum = 0;
        cur_length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            cur_length++;
            if (s[i] == ')') {
                cur_sum++;
            } else {
                cur_sum--;
            }
            if (cur_sum == 0) {
                res = max(res, cur_length);
            } else if (cur_sum < 0) {
                cur_sum = 0;
                cur_length = 0;
            }
        }
        return res;
    }
};
