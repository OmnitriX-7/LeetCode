class Solution {
public:
    string sortVowels(string s) {
        map<char, int> freq, priority;
        int d = 5;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            if (!priority.count(s[i])) {
                priority[s[i]] = d;
                d--;
            }
        }

        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        string vowels = "";
        
        for (char c : s) {
            if (st.count(c)) vowels += c;
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            if (freq[a] == freq[b]) return priority[a] > priority[b];
            return freq[a] > freq[b];
        });

        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (st.count(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};