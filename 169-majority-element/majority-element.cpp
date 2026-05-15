class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 1;
        int k = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == k) c++;
            else {
                c--;
                if (c < 0) {
                    c = 1;
                    k = nums[i];
                }
            }
        }
        return k;
    }
};