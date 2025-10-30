#include <vector>
#include <map>
#include <algorithm> // For min, max, and min_element

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }

        map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
        }

        // 1. Correct Initialization:
        // Start one before the earliest possible slot for the smallest element.
        int prev_end = *min_element(nums.begin(), nums.end()) - k - 1;
        int ans = 0;

        for (auto const& [num, count] : freq) {
            // Calculate the valid range [start_slot, end_slot] for the current number
            int start_slot = max(prev_end + 1, num - k);
            int end_slot = num + k;

            // 2. Correct Range Calculation:
            // Calculate the number of available slots.
            int available_slots = max(0, end_slot - start_slot + 1);

            if (available_slots > 0) {
                // Determine how many elements we can actually place
                int num_to_place = min(count, available_slots);
                
                ans += num_to_place;

                // 3. Correct Greedy Update:
                // Update prev_end to the last slot we actually used.
                prev_end = start_slot + num_to_place - 1;
            }
        }
        return ans;
    }
};