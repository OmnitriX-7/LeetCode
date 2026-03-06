class Solution {
public:
    bool checkOnesSegment(string s) {
        int segs = 0;
        if (s[0] == '1') segs++;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '1' && s[i-1] == '0') segs++; 
        }
        if (segs <= 1) return 1;
        return 0;
    }
};