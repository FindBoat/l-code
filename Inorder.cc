#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        vector<TreeNode*> stack;
        TreeNode *p = root;
        while (1) {
            while (p) {
                stack.push_back(p);
                p = p->left;
            }
            if (stack.empty()) return res;
            TreeNode *tmp = stack.back();
            stack.pop_back();
            res.push_back(tmp->val);
            p = tmp->right;
        }
    }
};
