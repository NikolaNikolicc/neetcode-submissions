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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        deque<TreeNode*> s;
        if (root) s.push_back(root);

        while (!s.empty()) {
            int size = s.size();
            vector<int> tmp;
            while (size) {
                TreeNode* elem = s.front();
                s.pop_front();
                size--;
                
                tmp.push_back(elem->val);
                if (elem->left) s.push_back(elem->left);
                if (elem->right) s.push_back(elem->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
