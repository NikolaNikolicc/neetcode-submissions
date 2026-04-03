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
private:
    int cnt = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root){
            return -1;
        }
        int ret = -1;
        ret = kthSmallest(root->left, k);
        if (ret != -1){
            return ret;
        }
        if (++cnt == k){
            return root->val;
        }
        ret = kthSmallest(root->right, k);
        if (ret != -1){
            return ret;
        }
        return -1;
    }
};
