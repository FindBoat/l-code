#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        for (int i = 1; i < n; i++) s = generate(s);
        return s;
    }

    string generate(string str) {
        string s;
        int count = 0;
        char c;
        for (int i = 0; i < str.length(); i++) {
            if (count == 0) {
                c = str[i];
                count++;
            } else if (str[i] == c) {
                count++;
            } else {
                stringstream ss;
                ss << count;
                s += ss.str() + c;
                count = 1;
                c = str[i];
            }
        }
        stringstream ss;
        ss << count;
        s += ss.str() + c;
        return s;
    }
};
