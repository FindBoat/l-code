#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string S, string T) {
        if (S == "" || T == "") return "";
        int hash[256];
        int total_need = 0;
        for (int i = 0; i < 256; i++) hash[i] = 0;
        for (int i = 0; i < T.length(); i++) {
            hash[T[i]]++;
            total_need++;
        }
        int have[256];
        for (int i = 0; i < 256; i++) have[i] = 0;
        int i = 0, j = 0, total_have = 0;
        int start = -1, length = S.length() + 1;
        while (j < S.length()) {
            have[S[j]]++;
            if (have[S[j]] <= hash[S[j]]) total_have++;
            while (total_have == total_need) {
                if (j - i + 1 < length) {
                    start = i;
                    length = j - i + 1;
                }
                have[S[i]]--;
                if (hash[S[i]] > have[S[i]]) total_have--;
                i++;
            }
            j++;
        }
        return length > S.length() ? "" : S.substr(start, length);
    }
};
