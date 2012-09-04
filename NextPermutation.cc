#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int pos = num.size() - 1;
        while (pos > 0 && num[pos - 1] >= num[pos]) pos--;
        if (pos >= 1) {
            int tmp = num[pos - 1];
            num[pos - 1] = num[num.size() - 1];
            num[num.size() - 1] = tmp;
        }
        sort(num.begin() + pos, num.end());
    }
};
