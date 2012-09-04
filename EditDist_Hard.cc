#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int mem[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) mem[i][n] = m - i;
        for (int i = 0; i < n + 1; i++) mem[m][i] = n - i;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    mem[i][j] = mem[i + 1][j + 1];
                } else {
                    mem[i][j] = 1 + min(min(mem[i + 1][j + 1], mem[i][j + 1]), mem[i + 1][j]);
                }
            }
        }
        return mem[0][0];
    }
};
