class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        unordered_map<int, int> freqCount;
        for (auto& p : mp) {
            freqCount[p.second]++;
        }

        for (int x : nums) {
            if (freqCount[mp[x]] == 1) {
                return x;
            }
        }

        return -1;
    }
};