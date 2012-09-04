#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hash;
        int i = 0, j = 0;
        int res = 0;
        while (j < s.length()) {
            if (hash.find(s[j]) == hash.end()) {
                hash.insert(pair<char, int>(s[j], j));
                res = max(res, j - i + 1);
                j++;
            } else {
                int index = hash[s[j]];
                while (i <= index) {
                    hash.erase(s[i]);
                    i++;
                }
            }
        }
        return res;
    }
};
