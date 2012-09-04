#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<string> > res;    
    vector<vector<string> > solveNQueens(int n) {
        if (n == 0) return res;
        int pos[n];
        doSolve(pos, 0, n);
        return res;
    }
    void doSolve(int *pos, int i, int n) {
        if ( i == n) {
            output(pos, n);
            return;
        }
        for (int k = 0; k < n; k++) {
            bool can = true;
            for (int j = 0; j < i; j++) {
                if ( k == pos[j] || k  - pos[j] == i - j || pos[j] - k == i - j) {
                    can = false;
                    break;
                }
            }
            if (can) {
                pos[i] = k;
                doSolve(pos, i + 1, n);
            }
        }
    }
    void output(int *pos, int n) {
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < pos[i]; j++) s += '.';
            s += 'Q';
            for (int j = pos[i] + 1; j < n; j++) s += '.';
            v.push_back(s);
        }
        res.push_back(v);
    }
    
};
int main () {
    Solution s;
    vector<vector<string> > res = s.solveNQueens(8);
    cout << res.size() << endl;
}
