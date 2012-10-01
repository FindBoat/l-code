#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > res;
    vector<int> array;
    vector<vector<int> > permute(vector<int> &num) {
        array = num;
        doPermute(0);
        return res;
    }
    void doPermute(int i) {
        if (i == array.size() - 1) {
            res.push_back(array);
            return;
        }
        for (int j = i; j < array.size(); j++) {
            swap(&array[i], &array[j]);
            doPermute(i + 1);
            swap(&array[i], &array[j]);
        }
    }
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};
