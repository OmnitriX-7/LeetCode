class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] != val) nums[p1++] = nums[i];
            i++;
        }

        return p1;
    }
};