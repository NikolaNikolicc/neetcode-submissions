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
    vector<int> queue;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> s;

        s.push({root, false});
        while (s.size()){
            const auto& pair = s.top();
            s.pop();
            if (!pair.first) continue;
            if (pair.second){
                queue.push_back(pair.first->val);
            } else {
                s.push({pair.first, true});
                s.push({pair.first->right, false});
                s.push({pair.first->left, false});
            }
        }
        return queue;
    }
};