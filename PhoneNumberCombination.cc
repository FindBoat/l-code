#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string digits;
    vector<char> prefix;
    vector<string> res;
    string *phone; 
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        string numbers[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        phone = numbers;
        doCombination(0);
        return res;
    }
    void doCombination(int i) {
        if (i == digits.length()) {
            string str;
            for (int k = 0; k < prefix.size(); k++) str += prefix[k];
            res.push_back(str);
            return;
        }
        int digit = digits[i] - '0';
        for (int k = 0; k < phone[digit].length(); k++) {
            prefix.push_back(phone[digit][k]);
            doCombination(i + 1);
            prefix.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("234");
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}
