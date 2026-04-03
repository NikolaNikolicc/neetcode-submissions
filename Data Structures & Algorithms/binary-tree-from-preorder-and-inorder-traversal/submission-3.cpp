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
    // halfopen [is, ie)
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre, int is, int ie){
        for(int i = is; i < ie; i++){
            if (inorder[i] == preorder[pre]){
                TreeNode* root = new TreeNode(preorder[pre]);
                // inorder between [is, i) and prepos > pre
                int prepos = pre;
                root->left = helper(preorder, inorder, prepos + 1, is, i);
                prepos = pre + i - is;

                // inorder between (i, ie) and prepos > pre
                root->right = helper(preorder, inorder, prepos + 1, i + 1, ie);

                return root;
            }
        }
        return nullptr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size());
    }
};