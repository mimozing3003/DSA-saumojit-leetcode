#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check for positive overflow before multiplying:
            // INT_MAX is 2,147,483,647 (ends in 7)
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
                return 0;
            }

            // Check for negative overflow before multiplying:
            // INT_MIN is -2,147,483,648 (ends in -8)
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
                return 0;
            }

            rev = rev * 10 + pop;
        }

        return rev;
    }
};