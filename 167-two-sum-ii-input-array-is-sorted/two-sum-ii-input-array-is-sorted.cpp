class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p = 0;
        int q = n-1;
        vector<int> ans;

        while (p < q) {
            int sum = numbers[p] + numbers[q];
            if (sum == target) {
                ans = {p+1, q+1};
                break;
            }
            else if (sum < target) p++;
            else q--;
        }
        return ans;
    }
};