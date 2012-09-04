#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        vector<int> left;
        left.push_back(0);
        for (int i = 1; i < height.size(); i++) 
            if (height[i] > height[left.back()]) left.push_back(i);
        int res = min(height[0], height[1]);
        int i = 0, right = -1;
        for (int j = height.size() - 1; j >= 0; j--) {
            if (height[j] > right) {
                right = height[j];
                bool stop = false;
                for (int k = i; k < left.size(); k++) {
                    if (stop) break;
                    int res_tmp = min(right, height[left[k]]) * (j - left[k]);
                    res = max(res, res_tmp);
                    if (height[left[k]] >= right) {
                        stop = true;
                        i = k;
                    }
                }
            }
        }
        return res;
    }
};
