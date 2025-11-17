class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for (int i= 0; i < n; i++){
            if (nums[i] == 1){
                if (prev == -1){
                    prev = i;
                }
                else {
                    if (i - prev <= k) return false;
                    prev = i;
                }
            }
        }
        return true;
    }
};