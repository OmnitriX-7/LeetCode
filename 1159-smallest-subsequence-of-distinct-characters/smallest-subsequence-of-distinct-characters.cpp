class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> inStack(26, false);
        string result = ""; 

        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i]-'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (inStack[c-'a']) {
                continue;
            }

            while (!result.empty() && result.back() > c && lastIndex[result.back()-'a'] > i) {
                inStack[result.back()-'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inStack[c-'a'] = true;
        }

        return result;
    }
};