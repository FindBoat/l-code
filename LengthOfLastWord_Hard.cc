#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int end = n - 1;
        while (end >= 0 && *(s + end) == ' ') end--;
        int start = end;
        while (start >= 0 && *(s + start) != ' ') start--;
        return end - start;
    }
};
