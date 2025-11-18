class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while (i < n){
            if (i == n-2){
                if (bits[i] == 0) return true;
                return false;
            }
            if (bits[i] == 1 && bits[i+1] == 0) i += 2;
            else if (bits[i] == 1 && bits[i+1] == 1) i += 2;
            else i += 1;
        }
        return true;
    }
};