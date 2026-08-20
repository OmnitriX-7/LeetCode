class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans1, ans2;
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if (ans1.back() > ans2.back()) ans1.push_back(nums[i]);
            else ans2.push_back(nums[i]);
        }
        
        for (auto& i : ans2) ans1.push_back(i);
        return ans1;
    }
};