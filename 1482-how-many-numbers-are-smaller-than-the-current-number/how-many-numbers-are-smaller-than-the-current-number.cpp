class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        vector<int> ans(n);
        int j = 0, i = 0;

        while(i < n){
            int val = v[i].first;
            ans[v[i].second] = j;

            int k = i + 1;
            while(k < n && v[k].first == val){
                ans[v[k].second] = j;
                k++;
            }

            j += (k - i);
            i = k;
        }

        return ans;
    }
};
