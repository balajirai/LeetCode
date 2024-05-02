class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size()-1;
        while(start < end){
            if(nums[start] == -1*nums[end]){
                return nums[end];
            }
            else if(nums[start] < -1*nums[end]) start++;
            else end--;
        }
        return -1;
    }
};