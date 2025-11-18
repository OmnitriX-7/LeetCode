class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int maxi = -1; int left_idx = -1;
        int maxi_idx = -1; int right_idx = -1;

        for (int i = n-1; i >= 0; i--){
            if (s[i] > maxi){
                maxi = s[i];
                maxi_idx = i;
            }
            else if (s[i] < maxi){
                left_idx = i;
                right_idx = maxi_idx;
            }
        } 

        if (left_idx == -1) return num;
        swap(s[left_idx], s[right_idx]);
        return stoi(s);
    }
};