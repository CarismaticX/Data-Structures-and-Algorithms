// C++ (optimal; reverse half)
// Uses long long for safety though half-reverse usually safe.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;

        long long reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + (x % 10);
            x /= 10;
        }
        // Even digits: x == reverted
        // Odd digits: x == reverted/10 (middle digit ignored)
        return x == reverted || x == reverted / 10;
    }
};
