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
    unordered_map<int, int> freq;

    int dfs(TreeNode* root){
        if (root == nullptr) return 0;
        int x = dfs(root->left) + dfs(root->right) + root->val;
        freq[x]++;
        return x;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        int maxi = 0;
        int max_f = 0;
        dfs(root);

        for (auto i : freq){
            if (i.second > max_f){
                max_f = i.second;
                maxi = i.first;
            }
        }
        for (auto i : freq){
            if (i.second == max_f){
                res.push_back(i.first);
            }
        }
        return res;
    }
};