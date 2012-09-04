#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        int mem[m][n];
        mem[m- 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--) mem[i][n - 1] = mem[i + 1][n - 1] + grid[i][n - 1];
        for (int i = n - 2; i >= 0; i--) mem[m- 1][i] = mem[m - 1][i + 1] + grid[m - 1][i];
        int i = m - 2, j = n - 2;
        while (i >= 0 && j >= 0) {
            for (int k = j; k >= 0; k--)
                mem[i][k] = grid[i][k] + min(mem[i + 1][k], mem[i][k + 1]);
            for (int k = i; k >= 0; k--)
                mem[k][j] = grid[k][j] + min(mem[k + 1][j], mem[k][j + 1]);
            i--;
            j--;
        }
        return mem[0][0];
    }
};
