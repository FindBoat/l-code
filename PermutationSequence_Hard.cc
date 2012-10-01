#include<string>
#include<list>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        list<int> remain;
        for (int i = 1; i <= n; i++) remain.push_back(i);
        string res;
        int total = 1;
        for (int i = 1; i < n; i++) total *= i;
        if (k > total * n) return res;
        list<int>::iterator it = remain.begin();
        for (int i = n - 1; i >= 0; i--) {
            int tmp = total;
            while (tmp < k) {
                tmp += total;
                it++;
            }
            res += *it + '0';
            cout << *it << endl;
            remain.erase(it);
            it = remain.begin();
            k -= tmp - total;
            if (i > 0) total /= i;
        }
        return res;
    }
};
int main() {
    Solution s;
    string res = s.getPermutation(3, 5);
    cout << res << endl;
}
