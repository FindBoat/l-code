#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        if (n == 0) return 0;
        int pos[n];
        doSolve(pos, 0, n);
        return res.size();
    }
    void doSolve(int *pos, int i, int n) {
        if ( i == n) {
            count++;
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
};
