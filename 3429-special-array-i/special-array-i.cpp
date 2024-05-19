class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            int a = nums[i], b = nums[i+1];
            if((a%2==0 && b%2==0) || (a%2==1 && b%2==1)) return false;
            else continue;
        }
        return true;
    }
};