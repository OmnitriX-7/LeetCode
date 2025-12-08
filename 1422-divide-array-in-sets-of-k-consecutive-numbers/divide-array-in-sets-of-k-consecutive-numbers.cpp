class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();

        if (n % k) return false;

        map<int, int> freq;
        for (auto i : nums) freq[i]++;

        while (!freq.empty()){
            int start = freq.begin()->first;
            for (int i = 0; i < k; i++){
                if (freq.find(start+i) == freq.end()) return false;
                if (--freq[start+i] == 0) freq.erase(start+i);
            }
        }

        return 1;
    }
};