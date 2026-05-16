class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<char> vowels;
        for (auto& i : s) {
            if (i == 'a' || i == 'A' || i == 'e' || i == 'E' || i == 'i' || i == 'I' || i == 'o' || i == 'O' || i == 'u' || i == 'U') {
                vowels.push_back(i);
            }
        }
        reverse(vowels.begin(), vowels.end());
        int j = 0;
        for (auto& i : s) {
            if (i == 'a' || i == 'A' || i == 'e' || i == 'E' || i == 'i' || i == 'I' || i == 'o' || i == 'O' || i == 'u' || i == 'U') {
                i = vowels[j++];
            }
        }
        return s;
    }
};