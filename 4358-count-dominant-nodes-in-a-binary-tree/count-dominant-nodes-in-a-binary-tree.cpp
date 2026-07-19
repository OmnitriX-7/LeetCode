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
    int postorder(TreeNode* root, int& c) {
        if (!root) return INT_MIN;
        int leftMax = postorder(root->left, c);
        int rightMax = postorder(root->right, c);
        
        int currMax = max({root->val, leftMax, rightMax});
        
        if (root->val == currMax) {
            c++;
        }
        
        return currMax;
    }

    int countDominantNodes(TreeNode* root) {
        int c = 0;
        postorder(root, c);
        return c;
    }
};