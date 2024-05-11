class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1, curr = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) curr++;
            else{
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        return max(maxi, curr);
    }
};