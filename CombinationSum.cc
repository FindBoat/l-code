#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        int cur = candidates[0];
        int n = target / candidates[0];
        if (candidates.size() == 1) {
            if (n > 0 && candidates[0] * n == target) {
                vector<int> tmp;
                for (int i = 0; i < n; i++) tmp.push_back(candidates[0]);
                res.push_back(tmp);
            }
            return res;
        }
        candidates.erase(candidates.begin());
        for (int i = 0; i <= n; i++) {
            vector<vector<int> > res_tmp = combinationSum(candidates, target - i * cur);
            if (res_tmp.size() > 0) {
                for (int k = 0; k < res_tmp.size(); k++) {
                    for (int j = 0; j < i; j++) res_tmp[k].insert(res_tmp[k].begin(), cur);
                    res.push_back(res_tmp[k]);
                }
            }
        }
        if (target > 0 && cur * n == target) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) tmp.push_back(cur);
            res.push_back(tmp);
        }
        candidates.insert(candidates.begin(), cur);
        return res;
    }
};
