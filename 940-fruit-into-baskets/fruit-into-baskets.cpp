class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0, maxLen = 0, unique = 0;

        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;
            if (freq[fruits[right]] == 1) unique++;

            while (unique > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) unique--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
