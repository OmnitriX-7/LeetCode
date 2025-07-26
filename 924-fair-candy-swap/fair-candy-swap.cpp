class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        vector<int> ans;

        int alice_total = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bob_total = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        for (int i = 0; i < aliceSizes.size(); i++) {
            int y = aliceSizes[i] + (bob_total-alice_total)/2;
            bool found = binary_search(bobSizes.begin(), bobSizes.end(), y);
            if (found){
                ans.push_back(aliceSizes[i]);
                ans.push_back(y);
                break;
            }
        }
        return ans;
    }
};