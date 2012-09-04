#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int a, int b) {
        return doDivide(a, b);
    }
    int doDivide(long long a, long long b) {
        bool reverse = (a < 0 && b > 0) || (a > 0 && b < 0);
        a = a < 0 ? -1 * a : a;
        b = b < 0 ? -1 * b : b;
        if (a < b) return 0;
        int res = 1;
        long long tmp = b;
        while ((tmp << 1) < a && (tmp << 1) > 0) {
            tmp <<= 1;
            res <<= 1;
        }
        res = res + doDivide(a - tmp, b);
        return reverse ? -1 * res : res;
    }
};
int main() {
    Solution s;
    cout << s.divide(-2147483648, -3) << endl;
}
