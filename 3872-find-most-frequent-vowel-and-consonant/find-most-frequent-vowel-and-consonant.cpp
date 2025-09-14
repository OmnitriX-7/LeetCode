class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        int x = 0, y = 0;
        for (auto i : freq) {
            char c = i.first;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') x = max(x, i.second);
            else y = max(y, i.second);
        }
        return x+y;
    }
};