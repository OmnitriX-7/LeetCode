class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, ans = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int size = q.size();
            long long curSum = 0;

            while (size--) {
                auto node = q.front(); q.pop();
                curSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (curSum > maxSum) {
                maxSum = curSum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
