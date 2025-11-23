class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> freq_s;
        map<char, int> freq_t;

        for (int i = 0; i < s.size(); i++){
            freq_s[s[i]]++;
            freq_t[t[i]]++;
        }

        int cnt = 0;

        for (auto i : freq_s){
            if (i.second > freq_t[i.first]) cnt += i.second - freq_t[i.first];
        }

        return cnt;
    }
};