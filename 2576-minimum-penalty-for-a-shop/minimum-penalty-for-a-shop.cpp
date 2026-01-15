class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int mn = INT_MAX;
        int total_yes = count(customers.begin(), customers.end(), 'Y');
        int cnt_no = 0; int cnt_yes = 0;
        int idx = -1;
        for (int i = 0; i < n; i++){
            int penalty = cnt_no + (total_yes - cnt_yes);
            if (penalty < mn){
                idx = i;
                mn = min(mn, penalty);
            }
            if (customers[i] == 'Y') cnt_yes++;
            else cnt_no++;
        }
        int penalty = cnt_no;   
        if (penalty < mn) idx = n;

        return idx;
    }
};