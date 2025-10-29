class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> minPrefix(n);
        minPrefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            minPrefix[i] = min(minPrefix[i-1], nums[i]);
        }

        stack<int> st;
        for (int j = n-1; j >= 0; j--){
            if (minPrefix[j] < nums[j]){
                while (!st.empty() && st.top() <= minPrefix[j]) st.pop();
                if (!st.empty() && st.top() < nums[j]) return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};