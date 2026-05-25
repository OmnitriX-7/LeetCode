class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[magazine[i]]++;
        }
        int m = ransomNote.size();
        for (int i = 0; i < m; i++) {
            if (!mp.count(ransomNote[i])) return false;
            if (mp[ransomNote[i]] == 0) return false;
            mp[ransomNote[i]]--;
        }
        return true;
    }
};