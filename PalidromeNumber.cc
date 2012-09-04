#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int base = 1;
        while (10 * base < x) base *= 10;
        int left = base, right = 1;
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
    cout << s.isPalindrome(12345);
}
