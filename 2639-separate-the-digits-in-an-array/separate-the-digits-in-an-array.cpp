class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for (int i = 0; i < n; i++){
            vector<int> r;
            int temp = nums[i];
            while (temp) {
                r.push_back(temp % 10);
                temp /= 10;
            }
            reverse(r.begin(), r.end());
            for (auto& i : r) v.push_back(i);
        }

        return v;
    }
};