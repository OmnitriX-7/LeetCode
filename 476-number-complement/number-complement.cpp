class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        for (int i = 0; i < (log2(num)); i++){
            int x = (num >> i) & 1;
            if (x == 0) ans += pow(2, i);
        }
        return ans;
    }
};