class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res;
        int final = INT_MIN;
        for (int i=0; i < n-2; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]){
                string s = num.substr(i, 3);
                int temp = stoi(s);
                if (temp > final){
                    final = temp;
                    res = s;
                }
            }
        }
        return res;
    }
};