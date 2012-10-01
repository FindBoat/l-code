using namespace std;
class Solution {
public:
    double pow(double x, int n) {
        return pow2(x, n);
    }

    double pow2(double x, long long n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 1.0 / pow2(x, -n);
        } else if (n & 1) {
            double tmp = pow2(x, (n - 1) >> 1);
            return x * tmp * tmp;
        } else {
            double tmp = pow2(x, n >> 1);
            return tmp * tmp;
        }
    }
};
