#include<iostream>
using namespace std;
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m = 0, n = 0;
        while (*(haystack + m) != '\0') m++;
        while (*(needle + n) != '\0') n++;
        int i = 0;
        while (i <= m - n) {
            bool find = true;
            for (int j = 0; j < n; j++) {
                if (*(haystack + i + j) != *(needle + j)) {
                    find = false;
                    break;
                }
            }
            if (find) return haystack + i;
            i++;
        }
        return NULL;
    }
};
