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
    void bfs(int& ans, TreeNode* root, string temp){
        if (!root) return;
        
        char c = char(root->val + '0');
        temp += c;
        if (!root->left && !root->right) {
            ans += stoi(temp);
            return;
        }
        bfs(ans, root->left, temp);
        bfs(ans, root->right, temp);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string temp;
        bfs(ans, root, temp);
        return ans;
    }
};