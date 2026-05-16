class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string z;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!z.empty()) {
                    v.push_back(z);
                    z = "";
                }
            }
            else {
                z += s[i];
            }
        }

        if (!z.empty()) v.push_back(z);

        reverse(v.begin(), v.end());
        string ans;
        for (auto& i : v) {
            ans += i;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};