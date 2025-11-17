class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int seg = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                seg++;
            }
            else {
                ans = max(ans, seg);
                seg = 0;
            }
        }
        if (seg){
            ans = max(ans, seg);
        }
        return ans;
    }
};