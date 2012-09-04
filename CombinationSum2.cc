#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        set<vector<int> > s = doSum(num, 0, target);
        vector<vector<int> > res(s.begin(), s.end());
        return res;
    }

    set<vector<int> > doSum(vector<int> &num, int i, int target) {
        set<vector<int> > res;
        int cur = num[i];
        if (cur == target) {
            vector<int> tmp;
            tmp.push_back(cur);
            res.insert(tmp);
            return res;
        }
        if (cur < target && i < num.size() - 1) {
            set<vector<int> > res_tmp = doSum(num, i + 1, target);
            set<vector<int> >::iterator it = res_tmp.begin();
            while (it != res_tmp.end()) {
                res.insert((*it));
                it++;
            }
            res_tmp = doSum(num, i + 1, target - cur);
            it = res_tmp.begin();
            while (it != res_tmp.end()) {
                vector<int> tmp = *it;
                tmp.insert(tmp.begin(), cur);
                res.insert(tmp);
                it++;
            }
        }
        return res;
    }
};
