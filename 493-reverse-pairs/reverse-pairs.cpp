class Solution {
public:
    void merge(int l, int mid, int r, vector<int>& nums, int& cnt){
        vector<int> left(nums.begin()+l, nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1, nums.begin()+r+1);

        int i = 0, j = 0, k = l;
        int p = 0, q = 0;

        while (p < left.size() && q < right.size()){
            if (1LL*left[p] > 1LL*2*right[q]){
                cnt += left.size()-p;
                q++;
            }
            else p++;
        }

        while (i < left.size() && j < right.size()){
            if (left[i] <= right[j]) nums[k++] = left[i++];
            else nums[k++] = right[j++];
        }

        while (i < left.size()) nums[k++] = left[i++];
        while (j < right.size()) nums[k++] = right[j++];
    }

    void mergeSort(int l, int r, vector<int>& nums, int& cnt){
        if (l < r){
            int mid = l + (r-l)/2;
            mergeSort(l, mid, nums, cnt);
            mergeSort(mid+1, r, nums, cnt);
            merge(l, mid, r, nums, cnt);
        }
    }

    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        mergeSort(0, nums.size()-1, nums, cnt);
        return cnt;
    }
};