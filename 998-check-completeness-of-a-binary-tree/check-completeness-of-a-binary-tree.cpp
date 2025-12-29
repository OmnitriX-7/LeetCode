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
    bool isComplete(TreeNode* root, long long i, long long totalNodes){
        if (!root) return true;

        if (i >= totalNodes) return false;

        return isComplete(root->left, 2*i+1, totalNodes) && isComplete(root->right, 2*i+2, totalNodes);
    }

    long long count(TreeNode* root){
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    bool isCompleteTree(TreeNode* root) {
        long long totalNodes = count(root);

        if (isComplete(root, 0, totalNodes)) return true;
        return false;
    }
};