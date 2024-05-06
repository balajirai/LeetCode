class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask = 0, number = n;
        while(number){
            number = number >> 1;
            mask = (mask << 1) | 1;
        }
        return ~n & mask;
    }
};