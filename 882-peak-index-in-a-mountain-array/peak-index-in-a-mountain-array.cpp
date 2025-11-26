class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1;
        int r = n-2;
        int ans = 0;

        while (l <= r){
            int m = l + (r-l)/2;
            if (arr[m] > arr[m-1] && arr[m] > arr[m+1]){
                ans = m;
                break;
            }
            else if (arr[m+1] > arr[m]) l = m+1;
            else r = m-1;
        }
        return ans;
    }
};