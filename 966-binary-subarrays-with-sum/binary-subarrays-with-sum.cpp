class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> freq;
        freq[0] = 1; 
        int prefix = 0, ans = 0;

        for (int x : nums) {
            prefix += x;
            if (freq.count(prefix - goal)) {
                ans += freq[prefix - goal];
            }
            freq[prefix]++;
        }
        return ans;
    }
};
