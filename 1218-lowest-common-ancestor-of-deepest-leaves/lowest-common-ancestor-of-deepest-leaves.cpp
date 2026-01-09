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
    TreeNode* LCA(TreeNode* root, TreeNode* ans, TreeNode* curr){
        if (!root || root == ans || root == curr) return root;

        TreeNode* L = LCA(root->left, ans, curr);
        TreeNode* R = LCA(root->right, ans, curr);

        if (L && R) return root;
        return L ? L : R;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> lastLevel;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int sz = q.size();
            lastLevel.clear();

            for (int i = 0; i < sz; i++){
                TreeNode* node = q.front(); q.pop();
                lastLevel.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        TreeNode* ans = lastLevel[0];
        for (int i = 1; i < lastLevel.size(); i++){
            ans = LCA(root, ans, lastLevel[i]);
        }

        return ans;
    }
};