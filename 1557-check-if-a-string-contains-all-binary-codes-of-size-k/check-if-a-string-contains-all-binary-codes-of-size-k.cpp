class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (k > n) return false;

        set<queue<char>> unique;
        queue<char> word;

        int i = 0;
        for (; i < k; i++) {
            word.push(s[i]);
        }
        unique.insert(word);

        for (; i < n; i++) {
            word.push(s[i]);
            word.pop();
            unique.insert(word);
        }

        return unique.size() == (1 << k);
    }
};