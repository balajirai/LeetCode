class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int bit=0; bit<=20; bit++){
            int xorVal = 0;
            for(int x:nums){
                int bitVal = (1 << bit) & x;
                xorVal = xorVal ^ bitVal;
            }
            int kBitVal = (1 << bit) & k;
            if(xorVal != kBitVal) ans++;
        }
        return ans;
    }
};