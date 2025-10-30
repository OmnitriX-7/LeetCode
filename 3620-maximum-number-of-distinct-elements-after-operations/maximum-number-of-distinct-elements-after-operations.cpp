class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
        }

        int prev_end = *min_element(nums.begin(), nums.end()) - k - 1;
        int ans = 0;

        for (auto const& [num, count] : freq) {
            int start_slot = max(prev_end + 1, num - k);
            int end_slot = num + k;

            int available_slots = max(0, end_slot - start_slot + 1);

            if (available_slots > 0) {
                int num_to_place = min(count, available_slots);
                ans += num_to_place;
                prev_end = start_slot + num_to_place - 1;
            }
        }
        return ans;
    }
};