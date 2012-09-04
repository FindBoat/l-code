using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        int *tmp = i < 0 ? B : A;
        int p = i < 0 ? j : i;
        while (p >= 0) A[k--] = tmp[p--];
    }
};
