class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(2001, 0);
        for (int i = 0; i < n; i++) {
            freq[arr[i]+1000]++;
        }
        sort(freq.begin(), freq.end());
        for (int i = 0; i < freq.size()-1; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] == freq[i+1]) return false;
        }
        return true;
    }
};