class Solution {
public:
    int getSum(int a, int b) {
        unsigned int na = static_cast<unsigned int>(a);
        unsigned int nb = static_cast<unsigned int>(b);

        unsigned int ans = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++) {
            int bit1 = (na >> i) & 1;
            int bit2 = (nb >> i) & 1;

            int sum = bit1 ^ bit2 ^ carry;
            if (sum) ans |= (1U << i);

            carry = (bit1 & bit2) | ((bit1 ^ bit2) & carry);
        }

        return static_cast<int>(ans);
    }
};
