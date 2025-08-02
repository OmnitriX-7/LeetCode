class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> freq;
        for (int i = 0; i < magazine.size(); i++) {
            freq[magazine[i]]++;
        }

        unordered_map<int, int> freq2;
        for (int i = 0; i < ransomNote.size(); i++) {
            freq2[ransomNote[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (freq[ransomNote[i]] < freq2[ransomNote[i]]) {
                return false;
            }
        }
        return true;
    }
};