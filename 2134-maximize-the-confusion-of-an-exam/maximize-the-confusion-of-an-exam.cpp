class Solution {
public:
    int solve(string answerKey, int k, char c){
        int l = 0, letter = 0, ans = 0;

        for (int r = 0; r < answerKey.size(); r++){
            if (answerKey[r] == c) letter++;

            while (letter > k){
                if (answerKey[l] == c) letter--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
        return res;
    }
};