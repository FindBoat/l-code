#include<iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while (1) {
                if (A[i] <= 0 || A[i] > n || A[i] == i + 1 || A[i] == A[A[i] - 1]) break;
                int tmp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
            if (A[i] != i + 1) return i + 1;
        return n + 1;
    }
};

int main() {
    int a[] = {-10,-3,-100,-1000,-239,1};
    int n = 6;
    Solution s;
    cout << s.firstMissingPositive(a, n) << endl;
}
