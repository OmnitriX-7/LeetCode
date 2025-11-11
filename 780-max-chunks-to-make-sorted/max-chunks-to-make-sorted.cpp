class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curr = 0;
        int prev = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++){
            int sum = i*(i+1)/2 - prev;
            curr += arr[i];
            if (curr == sum){
                cnt++;
                prev += curr;
                curr = 0;
            }
        }
        return cnt;
    }
};