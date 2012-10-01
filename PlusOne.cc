#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        if (digits.size() == 0) {
            res.push_back(1);
            return res;
        }
        bool carry = false;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int tmp = i == digits.size() - 1 ? digits[i] + 1 : digits[i] + carry;
            carry  = tmp > 9;
            tmp = carry ? tmp - 10 : tmp;
            res.insert(res.begin(), tmp);
        }
        if (carry) res.insert(res.begin(), 1);
        return res;
    }
};
