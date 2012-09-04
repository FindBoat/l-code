#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<string> addition;
        int max_digit = 0;
        for (int i = num2.length() - 1; i >= 0; i--) {
            int carry = 0;
            string multiply;
            for (int k = 0; k < num2.length() - i - 1; k++) multiply += '0';
            for (int j = num1.length() - 1; j >= 0; j--) {
                int tmp = (num1[j] - '0') * (num2[i] - '0') + carry;
                carry = tmp / 10;
                tmp -= 10 * carry;
                char c = tmp + '0';
                multiply = c + multiply;
            }
            if (carry > 0) {
                char c = carry + '0';
                multiply = c + multiply;
            }
            max_digit = max(max_digit, (int) multiply.length());
            addition.push_back(multiply);
        }
        string res;
        int carry = 0;
        for (int i = 1; i <= max_digit; i++) {
            int tmp = carry;
            for (int j = 0; j < addition.size(); j++) {
                if (addition[j].length() < i) continue;
                tmp += addition[j][addition[j].length() - i] - '0';
            }
            carry = tmp / 10;
            tmp -= 10 * carry;
            char c = tmp + '0';
            res = c + res;
        }
        while (carry > 0) {
            int tmp = carry % 10;
            carry /= 10;
            char c = tmp + '0';
            res = c + res;
        }
        return res;
    }
};

