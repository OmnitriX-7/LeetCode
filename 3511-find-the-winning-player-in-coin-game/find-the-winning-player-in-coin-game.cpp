class Solution {
public:
    string winningPlayer(int x, int y) {
        int turn = 1;
        while (x >= 1 && y >= 4){
            x--; y -= 4;
            turn *= -1;
        }
        if (turn == 1) return "Bob";
        return "Alice";
    }
};