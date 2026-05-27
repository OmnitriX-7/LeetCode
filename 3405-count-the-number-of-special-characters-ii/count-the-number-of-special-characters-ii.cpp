class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        map<char, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (islower(c)) mp[c] = i;
            else {
                if (!mp.count(c)) mp[c] = i;
            }
        }

        for (auto& i : mp) {
            char c = i.first;
            if (islower(c)) {
                if (mp.count(toupper(c)) && mp[toupper(c)] > mp[c]) ans++;
            }
            else {
                if (mp.count(tolower(c)) && mp[tolower(c)] < mp[c]) ans++;
            }
        }

        return ans/2;
    }
};