class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        
        for (int l = 0; l < n; l++) {
            unordered_map<int, int> cnt;
            unordered_map<int, int> freq;
            
            for (int r = l; r < n; r++) {
                int x = nums[r];
                if (cnt.count(x)) {
                    int c = cnt[x];
                    freq[c]--;
                    if (freq[c] == 0) {
                        freq.erase(c);
                    }
                }
                cnt[x]++;
                freq[cnt[x]]++;
                
                if (cnt.size() == 1) {
                    ans = max(ans, r-l+1);
                } else if (freq.size() == 2) {
                    auto it = freq.begin();
                    int f1 = it->first;
                    it++;
                    int f2 = it->first;
                    
                    if (f1 == 2*f2 || f2 == 2*f1) {
                        ans = max(ans, r-l+1);
                    }
                }
            }
        }
        return ans;
    }
};