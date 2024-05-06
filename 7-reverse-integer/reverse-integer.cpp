class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while(n){
            if((rev > INT_MAX/10) or rev < INT_MIN/10) return 0;
            int digit = n%10;
            n /= 10;
            rev = rev*10 + digit;

        }
        return rev;
    }
};