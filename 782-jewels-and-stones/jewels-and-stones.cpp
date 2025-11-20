class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<int, int> freq;
        for (auto i : stones){
            freq[i]++;
        }
        int cnt = 0;
        for (auto i : jewels){
            if (freq.find(i) != freq.end()){
                cnt += freq[i];
            }
        }
        return cnt;
    }
};