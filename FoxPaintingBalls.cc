#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class FoxPaintingBalls {
public:
    long long theMax(long long R, long long G, long long B, int N) {
        long long num_balls = (1 + N) * N / 2;
        cout << num_balls << endl;
        long long r, g, b;
        r = num_balls / 3;
        if (r * 3 == num_balls) {
            g = r;
            b = r;
        } else {
            g = r + 1;
            b = num_balls - r - g;
        }
        long long min_have = min(min(R, G), B);
        long long min_need = min(min(r, g), b);
        if (min_need == 0)  {
            return R + G + B;
        }
        long long res1 = min_have / min_need;
        long long res2 = (R + G + B) / (r + g + b);
        return min(res1, res2);
    }

    void sort(long long *a, long long *b, long long *c) {
        if (*b < *c) {
            long long tmp = *b;
            *b = *c;
            *c = tmp;
        }
        if (*a < *b) {
            long long tmp = *a;
            *a = *b;
            *b = tmp;
        }
        if (*b < *c) {
            long long tmp = *b;
            *b = *c;
            *c = tmp;
        }
    }
};

int main() {
    FoxPaintingBalls f;
    cout << f.theMax(1, 1, 1, 1) << endl;
}
