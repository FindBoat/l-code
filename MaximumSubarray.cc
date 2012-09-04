#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray2(int A[], int n) {
        int max_num = A[0];
        for (int i = 1; i < n; i++) max_num = max(max_num, A[i]);
        if (max_num < 0) return max_num;
        int res = 0, cur_sum = 0;
        for (int i = 0; i < n; i++) {
            cur_sum += A[i];
            res = max(res, cur_sum);
            if (cur_sum < 0) cur_sum = 0;
        }
        return res;
    }

    // Divide & conquer solution.
    int maxSubArray(int A[], int n) {
        if (n == 1) return A[0];
        int mid = n / 2;
        int res_left = maxSubArray(A, mid);
        int res_right = maxSubArray(A + mid, n - mid);
        int res_mid_left = A[mid - 1], res_mid_right = A[mid];
        int tmp1 = 0, tmp2 = 0;
        for (int i = mid - 1; i >= 0; i--) {
            tmp1 += A[i];
            res_mid_left = max(res_mid_left, tmp1);
        }
        for (int i = mid; i < n; i++) {
            tmp2 += A[i];
            res_mid_right = max(res_mid_right, tmp2);
        }
        int res_mid = res_mid_left + res_mid_right;
        return max(max(res_left, res_right), res_mid);
    }
};
