#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        bool carry = false;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0) {
            int t1 = i >= 0 ? a[i] - '0' : 0;
            int t2 = j >= 0 ? b[j] - '0': 0;
            int tmp = t1 + t2;
            if (carry) tmp++;
            if (tmp == 0) {
                carry = false;
                res = '0' + res;
            } else if (tmp == 1) {
                carry = false;
                res = '1' + res;
            } else if (tmp == 2) {
                carry = true;
                res = '0' + res;
            } else {
                carry = true;
                res = '1' + res;
            }
            i--;
            j--;
            // cout << t1 << ", " << t2 << endl;
            // cout << res << endl;
        }
        if (carry) res = '1' + res;
        return res;
    }
};

int main() {
    Solution c;
    string a("11");
    string b("1");
    cout << c.addBinary(a, b) << endl;
}
