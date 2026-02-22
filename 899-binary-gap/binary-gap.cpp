class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        for (int i = 0; i <= 31; i++){
            if ((1 << i) & n){
                if (prev != -1) ans = max(ans, i-prev);
                prev = i;
            }
        }
        return ans;
    }
};