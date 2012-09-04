#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int start = -1, length = -1;
        for (int i = 0; i < s.length(); i++) {
            int k = 0;
            while (i - k >= 0 && i + k < s.length() && s[i - k] == s[i + k]) k++;
            if (length < 2 * k - 1) {
                start = i - k;
                length = 2 * k - 1;
            }
            k = 0;
            while (i - k >= 0 && i +1 + k < s.length() && s[i - k] == s[i + 1 + k]) k++;
            if (length < 2 * k) {
                start = i - k;
                length = 2 * k;
            }
        }
        if (start == -1) return "";
        return s.substr(start, length);
    }
};
