#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<char> pre;
    vector<string> generateParenthesis(int n) {
        if (n > 0) doGenerate(0, 0, n);
        return res;
    }
    void doGenerate(int left, int right, int n) {
        if (left == n && right == n) {
            string s;
            for (int i = 0; i < pre.size(); i++) s += pre[i];
            res.push_back(s);
            return;
        }
        if (left < n) {
            pre.push_back('(');
            doGenerate(left + 1, right, n);
            pre.pop_back();
        }
        if (left > right && left <= n) {
            pre.push_back(')');
            doGenerate(left, right + 1, n);
            pre.pop_back();
        }
    }
};
int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(8);
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}
