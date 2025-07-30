class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int maxlen = 0; 
        int currlen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) {
                currlen++;
            }
            else {
                maxlen = max(maxlen, currlen);
                currlen = 0;
            }
        }

        return max(maxlen, currlen);
    }
};