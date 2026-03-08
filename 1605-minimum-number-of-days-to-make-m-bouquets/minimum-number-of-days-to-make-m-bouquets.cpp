class Solution {
public:
    int check(vector<int>& bloomDay, int mid, int m, int k){
        int cnt = 0;
        int curr = 0;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= mid){
                curr++;
                if (curr == k){
                    cnt++;
                    curr = 0;
                }
            }
            else curr = 0;
        }
        return cnt >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n/k) return -1;
        
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = r;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (check(bloomDay, mid, m, k)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};