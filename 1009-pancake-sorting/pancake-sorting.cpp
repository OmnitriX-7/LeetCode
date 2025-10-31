class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        while (n > 1){
            int maxi = *max_element(arr.begin(), arr.begin()+n);
            int i = 0;
            for (; i < n; i++){
                if (arr[i] == maxi){
                    ans.push_back(i+1);
                    ans.push_back(n);
                    break;
                }
            }
            reverse(arr.begin(), arr.begin()+i+1);
            reverse(arr.begin(), arr.begin()+n);
            n--;
        }
        return ans;
    }
};