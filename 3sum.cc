class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        int i = 0;
        while (i < num.size()) {
            int j = i + 1, k = num.size() - 1;
            while (j < k) {
                if (num[i] + num[j] + num[k] < 0) {
                    j++;
                } else if (num[i] + num[j] + num[k] > 0) {
                    k--;
                } else {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    res.push_back(tmp);
                    j++;
                    k--;
                    while (j < k && num[j] == num[j - 1]) j++;
                    while(j < k && num[k] == num[k + 1]) k--;
                }
            }
            i++;
            while (i < num.size() && num[i] == num[i - 1]) i++;
        }
        return res;
    }
};
