class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> freq;
        for (auto i : arr){
            freq[((i % k) + k) % k]++;
        }
        
        if (freq[0] % 2 != 0) return false;

        for (int i = 1; i < k; i++){
            if (freq[i] != freq[k-i]) return false;
        }
        return true;
    }
};