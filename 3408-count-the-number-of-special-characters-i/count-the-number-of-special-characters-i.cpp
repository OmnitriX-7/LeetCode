class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        set<char> s(word.begin(), word.end());
        int ans = 0;
        for (auto& c : s) {
            if (islower(c)) {
                if (s.count(toupper(c))) ans++;
            }
            else {
                if (s.count(tolower(c))) ans++;
            }
        }
        return ans/2;
    }
};