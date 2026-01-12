class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipped(n,0);
        int flips = 0;
        int ans = 0;

        for (int i = 0; i <= n-k; i++){
            if (i >= k) flips -= flipped[i-k];

            int curr = nums[i];

            if (flips % 2) curr ^= 1;

            if (curr == 0) {
                flips++;
                flipped[i] = 1;
                ans++;
            }
        }

        for (int i = n-k+1; i < n; i++){
            if (i >= k) flips -= flipped[i-k];

            int curr = nums[i];
            if (flips % 2) curr ^= 1;
            if (curr == 0) return -1;
        }

        return ans;
    }
};