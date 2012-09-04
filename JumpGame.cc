#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canJump(int A[], int n) {
        int cur = 0;
        while (cur != n - 1) {
            if (A[cur] == 0) return false;
            int index = -1;
            for (int i = cur + 1; i <= min(cur + A[cur], n - 1); i++) 
                if (index == -1 || index + A[index] < i + A[i]) index = i;
            cur = index;
        }
        return true;
    }
    
    bool canJump2(int A[], int n) {
        vector<int> zeros;
        for (int i = 0; i < n; i++)
            if (A[i] == 0 && i != n - 1) zeros.push_back(i);
        int m = -1;
        for (int i = 0; i < zeros.size(); i++) {
            int start = (i == 0) ? 0 : zeros[i - 1] + 1;
            int end = zeros[i] - 1;
            for (int j = start; j <= end; j++) m = max(m, A[j] + j);
            if (m <= zeros[i]) return false;
        }
        return true;
    }
};
