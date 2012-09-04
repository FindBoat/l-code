#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        map<int, vector<pair<int, int> > > hash;
        set<vector<int> > res;
        for (int i = 0; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                int need = target - num[i] - num[j];
                if (hash.find(need) != hash.end()) {
                    vector<pair<int, int> > v = hash[need];
                    for (int k = 0; k < v.size(); k++) {
                        vector<int> tmp;
                        tmp.push_back(v[k].first);
                        tmp.push_back(v[k].second);
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        sort(tmp.begin(), tmp.end());
                        res.insert(tmp);
                    }
                }
            }
            for (int j = 0; j < i; j++) {
                int sum = num[i] + num[j];
                if (hash.find(sum) == hash.end()) {
                    vector<pair<int, int> > v;
                    hash.insert(pair<int, vector<pair<int, int> > >(sum, v));
                }
                pair<int, int> p(num[i], num[j]);
                hash[sum].push_back(p);
            }
        }
        vector<vector<int> > v(res.begin(), res.end());
        return v;
    }
};

int main() {
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> array(a, a + 6);
    int t = 0;
    Solution s;
    vector<vector<int> > r = s.fourSum(array, t);
    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) cout << r[i][j] << ',';
        cout << endl;
    }
}
