class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        int maxi = -1;
        for (auto [x,y] : freq) {
            if (x == y) {
                maxi = max(maxi, x);
            }
        }
        return maxi;
    }
};