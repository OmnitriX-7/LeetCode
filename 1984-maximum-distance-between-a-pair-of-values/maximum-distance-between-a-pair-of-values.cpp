class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int low = i;
            int high = m-1;
            int curr = -1;
            while (low <= high) {
                int mid = low + (high-low)/2;
                if (nums2[mid] < nums1[i]) {
                    high = mid - 1;
                }
                else {
                    curr = mid-i;
                    low = mid+1;
                }
            }
            ans = max(ans, curr);
        }
        return ans == -1 ? 0 : ans;
    }
};