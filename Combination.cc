#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> pre;
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        doCombine(n, k);
        return res;
    }
    void doCombine(int n, int k) {
        if (k == 0) {
            res.push_back(pre);
            return;
        }
        if (n < 1) return;
        doCombine(n - 1, k);
        pre.push_back(n);
        doCombine(n - 1, k - 1);
        pre.pop_back();
    }
};
int main() {
    Solution s;
    vector<vector<int> > res = s.combine(4, 2);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << ',';
        cout << endl;
    }
}
