#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        int res = 0;
        int cur = 0;
        while (cur != n - 1) {
            res++;
            if (cur + A[cur] >= n - 1) return res;
            if (A[cur] == 0) return -1;
            int index = -1;
            for (int i = cur + 1; i <= min(cur + A[cur], n - 1); i++) {
                if (i + A[i] >= n - 1) return res + 1;
                if (index == -1 || index + A[index] < i + A[i]) index = i;
            }
            cur = index;
        }
        return res;
    }
};
