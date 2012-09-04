#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, pair<string, bool> > hash;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (hash.find(tmp) != hash.end()) {
                map<string, pair<string, bool> >::iterator it = hash.find(tmp);
                if (!(*it).second.second) {
                    res.push_back((*it).second.first);
                    (*it).second.second = true;
                }
                res.push_back(strs[i]);
            } else {
                pair<string, bool> p(strs[i], false);
                hash.insert(pair<string, pair<string, bool> >(tmp, p));
            }
        }
        return res;
    }
}; 
