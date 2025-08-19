class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int lo = 0, hi = nums.size()-1;

        while (lo < hi) {
            int mid = lo + (hi-lo)/2;

            if (nums[mid] < target) lo = mid+1;
            else hi = mid;
        }

        int low = 0, up = nums.size();

        while (low < up) {
            int mid = low + (up-low)/2;

            if (nums[mid] <= target) low = mid+1;
            else up = mid;
        }

        if (nums[lo] == target) return {lo, up-1};
        return {-1, -1};
    }
};