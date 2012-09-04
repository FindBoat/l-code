#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int base = 1;
        for (int i = 1; i <= n; i++) {
            int m = res.size();
            for (int j = m - 1; j >= 0; j--) res.push_back(base + res[j]);
            base <<= 1;
        }
        return res;
    }
};
