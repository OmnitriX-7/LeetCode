class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int l = 0;
        int ans = 0;
        int pref = 0;

        for (int r = 0; r < n; r++){
            if (nums[r] % 2) {
                cnt++;
                pref = 0;
            }

            while (cnt > k){
                if (nums[l] % 2) cnt--;
                l++;
            }

            while (cnt == k && nums[l] % 2 == 0){
                pref++;
                l++;
            }

            if (cnt == k) ans += pref + 1;
        }
        return ans;
    }
};
