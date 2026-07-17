using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> count(mx+1, 0);
        for (auto x : nums) {
            count[x]++;
        }

        vector<long long> gcdFreq(mx+1, 0);
        for (int i = mx; i >= 1; i--) {
            long long k = 0;
            for (int j = i; j <= mx; j += i) {
                k += count[j];
            }
            
            long long pairs = k*(k-1)/2;
            
            for (int j = 2*i; j <= mx; j += i) {
                pairs -= gcdFreq[j];
            }
            gcdFreq[i] = pairs;
        }

        for (int i = 1; i <= mx; i++) {
            gcdFreq[i] += gcdFreq[i-1];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto q : queries) {
            long long target = q+1;
            auto it = lower_bound(gcdFreq.begin()+1, gcdFreq.end(), target);
            ans.push_back(distance(gcdFreq.begin(), it));
        }

        return ans;
    }
};