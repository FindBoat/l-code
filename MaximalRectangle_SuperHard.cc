#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// Time complexity O(mn), space complexity O(m).
// Solution based on http://www.drdobbs.com/database/the-maximal-rectangle-problem/184410529 and http://stackoverflow.com/questions/2478447/find-largest-rectangle-containing-only-zeros-in-an-nn-binary-matrix.
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        int *hist = new int[n];
        for (int i = 0; i < n; i++) hist[i] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    hist[j] = 0;
                } else {
                    hist[j]++;
                }
            }
            res = max(res, maxHistogram(hist, n));
        }
        delete[] hist;
        return res;
    }

    int maxHistogram(int *hist, int n) {
        int res = 0;
        stack<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && hist[i] < hist[stack.top()]) {
                int h = hist[stack.top()];
                stack.pop();
                int left = stack.empty() ? -1 : stack.top();
                res = max(res, h * (i - left - 1));
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            int h = hist[stack.top()];
            stack.pop();
            int left = stack.empty() ? -1 : stack.top();
            res = max(res, h * (n - left - 1));
        }
        return res;
    }
};
