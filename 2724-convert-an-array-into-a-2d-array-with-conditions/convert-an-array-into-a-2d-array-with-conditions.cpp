class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        
        for (int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> res;
        int x = n;
        while (x){
            vector<int> v;
            for (int i = 1; i < freq.size(); i++){
                if (freq[i] > 0){
                    freq[i]--;
                    v.push_back(i);
                }
            }
            x -= v.size();
            res.push_back(v);
        }
        return res;
    }
};