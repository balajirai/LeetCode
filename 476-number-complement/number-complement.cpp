class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0; // start with all bits set to 1

        // Shift the mask until it's just covering the bits of 'num'
        while (num & mask) {
            mask <<= 1;
        }

        // XOR the num with the inverted mask to get the complement
        return ~num & ~mask;
    }
};