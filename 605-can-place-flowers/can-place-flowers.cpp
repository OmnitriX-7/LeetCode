class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = -1;
        int t = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1){
                if (prev == -1){
                    t += i/2;
                    prev = i;
                    continue;
                }
                int l = i-prev-1;
                if (l % 2 == 0){
                    t += l/2 - 1;
                }
                else {
                    t += l/2;
                }
                prev = i;
            }
        }
        if (prev != -1)
            t += (flowerbed.size()-(prev+1))/2;

        else {
            double f = flowerbed.size();
            t += ceil(f/(double)2);
        }
        if (t >= n) return true;
        return false;
    }
};