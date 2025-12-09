class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans(m, true);

        for (int j = 0; j < m; j++){
            vector<int> temp(nums.begin()+l[j], nums.begin()+r[j]+1);
            sort(temp.begin(), temp.end());

            if (temp.size() == 1) continue;

            int d = temp[1]-temp[0];

            for (int i = 2; i < temp.size(); i++){
                if (temp[i] - temp[i-1] != d){
                    ans[j] = false;
                    break;
                }
            }
        }

        return ans;
    }
};