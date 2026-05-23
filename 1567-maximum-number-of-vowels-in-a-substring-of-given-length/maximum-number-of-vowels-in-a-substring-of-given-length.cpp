class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowels = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowels++;
            }
        }
        int x = vowels;
        for (int i = k; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                x++;
            }
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                x--;
            }
            vowels = max(vowels, x);
        }
        return vowels;
    }
};