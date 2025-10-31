class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> freq;
        for (auto c : s) freq[c]++;
        int cnt = 0;
        int done = 0;
        for (auto i : freq){
            if (i.second % 2 == 0) {
                cnt += i.second;
            }
            else {
                cnt += i.second-1;
                if (!done) {
                    cnt += 1;
                    done = 1;
                }
            }
        }
        return cnt;
    }
};