class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p = 0, q = 0;
        int ans = -1;
        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] == nums2[q]) {
                ans = nums1[p];
                break;
            }
            else if (nums1[p] < nums2[q]) p++;
            else q++;
        }
        return ans;
    }
};