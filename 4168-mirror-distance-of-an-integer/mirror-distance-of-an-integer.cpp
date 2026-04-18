class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int x = n;
        while (x){
            int z = x % 10;
            x /= 10;
            rev = rev * 10 + z;
        }
        return abs(rev-n);
    }
};