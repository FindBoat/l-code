#include<iostream>
using namespace std;
// Be careful that 10 * base might overflow.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long base = 1;
        while (10 * base <= x) base *= 10;
        long long left = base, right = 1;
        while (left > right) {
            int left_digit = ((x - x % left) / left) % 10;
            int right_digit = ((x - x % right) / right) % 10;
            if (left_digit != right_digit) return false;
            left /= 10;
            right *= 10;
        }
        return true;
    }
};
int main() {
    Solution s;
    cout << s.isPalindrome(2147483647);
}
