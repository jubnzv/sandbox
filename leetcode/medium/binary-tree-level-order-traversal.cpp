#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution() : first_level_(true) {}
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return NULL;
        if (root->left != )
        return std::vector<int>(levelOrder(root->left), levelOrder(root->right));
    }

private:
    bool first_level_;
};
