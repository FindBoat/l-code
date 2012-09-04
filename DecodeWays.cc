#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int* mem;
    string str;
    int n;
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        str = s;
        n = s.length();
        mem = new int[n];
        for (int i = 0; i < n; i++) mem[i] = -1;
        int res = dp(0);
        delete[] mem;
        return res;
    }
    int dp(int i) {
        if (i >= n) return 1;
        if (mem[i] != -1) return mem[i];
        if (str[i] == '0') {
            mem[i] = 0;
            return mem[i];
        }
        if (i == n - 1) {
            mem[i] = 1;
            return mem[i];
        }
        int tmp = (str[i] - '0') * 10 + (str[i + 1] - '0');
        if (tmp <= 26) {
            mem[i] = dp(i + 1) + dp(i + 2);
        } else {
            mem[i] = dp(i + 1);
        }
        return mem[i];
    }
};
