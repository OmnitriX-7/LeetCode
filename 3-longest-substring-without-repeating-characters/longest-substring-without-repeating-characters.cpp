class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> counter(128, 0); 
        int left = 0, right = 0;
        int res = 0;

        while (right < s.size()) {
            counter[s[right]]++;

            while (counter[s[right]] > 1) {
                counter[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
