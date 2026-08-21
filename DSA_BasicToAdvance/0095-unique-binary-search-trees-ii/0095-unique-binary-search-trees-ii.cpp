class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};

        return build(1, n);
    }

private:
    vector<TreeNode*> build(int left, int right) {
        vector<TreeNode*> result;

        if (left > right) {
            result.push_back(nullptr);
            return result;
        }

        for (int root = left; root <= right; root++) {
            vector<TreeNode*> leftTrees = build(left, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, right);

            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }

        return result;
    }
};