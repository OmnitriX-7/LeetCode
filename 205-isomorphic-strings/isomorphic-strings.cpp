class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        map<char, char> mp;
        map<char, bool> used;
        
        for (int i = 0; i < n; i++) {
            if (mp.count(s[i])) {
                if (mp[s[i]] != t[i]) return false;
            } else {
                if (used[t[i]]) return false;
                mp[s[i]] = t[i];
                used[t[i]] = true;
            }
        }

        return true;
    }
};