#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int p = 1, q = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = p + q;
            p = q;
            q = tmp;
        }
        return q;
    }
};
