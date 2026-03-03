class Solution {
public:
    char findKthBit(int n, int k) {
        string s1 = "0";
        for (int i = 0; i < n; i++){
            string s2 = s1;
            for (auto& j : s2){
                if (j == '0') j = '1';
                else j = '0';
            }
            reverse(s2.begin(), s2.end());
            s1 = s1 + '1' + s2;
        }
        return s1[k-1];
    }
};