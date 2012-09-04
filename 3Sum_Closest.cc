class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size(); i++) {
            int start = i + 1, end = num.size() - 1;
            while (start < end) {
                int tmp = num[i] + num[start] + num[end];
                if (abs(res - target) > abs(tmp - target)) res = tmp;
                if (tmp < target) {
                    start++;
                } else if (tmp > target) {
                    end--;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};
