class MyCalendar {
private:
    struct TreeNode {
        int start, end;
        TreeNode *left, *right;

        TreeNode(int start, int end) : start(start), end(end), left(nullptr), right(nullptr) {}
    };
    TreeNode *root;

    bool insert(TreeNode *node, int start, int end) {
        if (end <= node->start) {
            if (!node->left) {
                node->left = new TreeNode(start, end);
                return true;
            }
            return insert(node->left, start, end);
        } else if (start >= node->end) {
            if (!node->right) {
                node->right = new TreeNode(start, end);
                return true;
            }
            return insert(node->right, start, end);
        }
        return false;
    }

public:
    MyCalendar() : root(nullptr) {}

    bool book(int startTime, int endTime) {
        if (!root) {
            root = new TreeNode(startTime, endTime);
            return true;
        }
        return insert(root, startTime, endTime);
    }
};