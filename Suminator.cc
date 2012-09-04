#include<iostream>
#include<vector>
using namespace std;
class Suminator {
public:
    long long getResult(vector<int> program) {
        vector<long long> stack;
        for (int i = 0; i < program.size(); i++) {
            if (program[i] == 0) {
                long long tmp1 = stack.empty() ? 0 : stack.back();
                if (!stack.empty()) stack.pop_back();
                long long tmp2 = stack.empty() ? 0 : stack.back();
                if (!stack.empty()) stack.pop_back();
                stack.push_back(tmp1 + tmp2);
            } else {
                stack.push_back(program[i]);
            }
        }
        return stack.empty() ? 0 : stack.back();
    }
    
    int findMissing(vector<int> program, int wantedResult) {
        int pos = 0;
        for (int i = 0; i < program.size(); i++)
            if (program[i] == -1) pos = i;
        program[pos] = 0;
        if (getResult(program) == wantedResult) return 0;
        program[pos] = 1;
        long long res1 = getResult(program);
        program[pos] = 2;
        long long res2 = getResult(program);
        if (res1 == res2) return -1;
        long long res = 1 + wantedResult - res1;
        return res > 0 ? res : -1;
    }
};

int main() {
    int w = 1000000000;
    int a[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
    vector<int> p(a, a + 9);
    Suminator s;
    cout << s.findMissing(p, w) << endl;
}
