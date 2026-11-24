/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int ans = 0;

        queue<TreeNode*> qu;

        qu.push(root);

        while (!qu.empty()) {
            int sz = qu.size();
            ans++;
            while (sz--) {
                auto node = qu.front();
                qu.pop();

                if (node->left) {
                    qu.push(node->left);
                }
                if (node->right) {
                    qu.push(node->right);
                }
            }
        }

        return ans;
    }
};
