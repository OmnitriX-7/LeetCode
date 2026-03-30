class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<char> a1,a2,b1,b2;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                a1.push_back(s1[i]);
                b1.push_back(s2[i]);
            }
            else {
                a2.push_back(s1[i]);
                b2.push_back(s2[i]);
            }
        }

        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());

        if (a1 != b1) return false;

        if (a2 != b2) return false;

        return true;
    }
};