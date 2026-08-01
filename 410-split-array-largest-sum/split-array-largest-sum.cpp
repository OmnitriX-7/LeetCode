class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        
        int res = 0;
        
        while (left <= right) {
            long long mid = left+(right-left)/2;
            
            int curr_sum = 0;
            int subarrays = 1;
            
            for (int num : nums) {
                if (curr_sum+num > mid) {
                    subarrays++;
                    curr_sum = num;
                } 
                else {
                    curr_sum += num;
                }
            }
            
            if (subarrays <= k) {
                res = mid;
                right = mid-1;
            } 
            else {
                left = mid+1;
            }
        }
        
        return res;
    }
};