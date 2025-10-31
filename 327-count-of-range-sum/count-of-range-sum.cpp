class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        long long count = 0;
        multiset<long long> s;

        for (auto x : pre)
            s.insert(x);

        for (int i = 0; i <= n; i++) {
            s.erase(s.find(pre[i])); 
            
            long long low = pre[i] + lower;
            long long high = pre[i] + upper;

            auto it1 = s.lower_bound(low);
            auto it2 = s.upper_bound(high);

            count += distance(it1, it2);
        }
        return count;
    }
};