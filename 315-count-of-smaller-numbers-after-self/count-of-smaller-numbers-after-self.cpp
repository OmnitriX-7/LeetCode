class Solution {
public:
    void Merge(vector<pair<int, int>>& arr, int l, int m, int r, vector<int>& ans) {
            vector<pair<int, int>> left(arr.begin()+l, arr.begin()+m+1);
            vector<pair<int, int>> right(arr.begin()+m+1, arr.begin()+r+1);

            int p1 = 0, p2 = 0, k = l;
            int cnt = 0;
            while (p1 < left.size() && p2 < right.size()){
                if (left[p1].first <= right[p2].first){
                    ans[left[p1].second] += cnt;
                    arr[k++] = left[p1++];
                }
                else {
                    cnt++;
                    arr[k++] = right[p2++];
                }
            }

            while (p1 < left.size()) {
                ans[left[p1].second] += cnt;
                arr[k++] = left[p1++];
            }
            while (p2 < right.size()) arr[k++] = right[p2++];
    }

    void mergeSort(vector<pair<int, int>>& arr, int l, int r, vector<int>& ans){
        if (l < r) {
            int m = (l + r)/2;
            mergeSort(arr, l, m, ans);
            mergeSort(arr, m+1, r, ans);
            Merge(arr, l, m, r, ans);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        vector<int> ans(n,0);
        mergeSort(arr, 0 , n-1, ans);
        return ans;
    }
};