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
    int i = 0;
    TreeNode* construct(vector<int>& preorder, int maxi){
        if (i == preorder.size() || preorder[i] > maxi){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = construct(preorder, node->val);
        node->right = construct(preorder, maxi);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = construct(preorder, INT_MAX);
        return head;
    }
};