class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string target = strs[0];
        int i = 0;
        for (; i < target.size(); i++) {
            int done = 0;
            for (int j = 1; j < strs.size(); j++) {
                if (i > strs[j].size()-1 || strs[j][i] != target[i]) {
                    done = 1;
                    break;
                }
            }
            if (done) break;
        }
        return target.substr(0, i);
    }
};