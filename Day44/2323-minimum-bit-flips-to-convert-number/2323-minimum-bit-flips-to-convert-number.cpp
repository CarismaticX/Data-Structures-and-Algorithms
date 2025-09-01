class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal; // XOR to find differing bits
        int count = 0;
        while (x) {
            count += (x & 1);
            x >>= 1;
        }
        return count;
    }
};
