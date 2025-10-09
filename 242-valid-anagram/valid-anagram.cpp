class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]-'a']++;
        }
        for (auto i : t) {
            freq[i-'a']--;
        }
        for (auto i : freq){
            if (i != 0) return false;
        }
        return true;
    }
};