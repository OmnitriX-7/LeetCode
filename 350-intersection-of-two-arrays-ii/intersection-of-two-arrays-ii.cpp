class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        if (nums2.size() < nums1.size())
            swap(nums1, nums2);

        for (int i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }

        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {
            if (freq.find(nums2[i]) != freq.end() && freq[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }

        return ans;
    }
};