class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        int start = nums[i], end = nums[n-1];
        while(start < end && i < n){
            if(start != nums[i]){
                ans.push_back(start);
            }
            else i++;
            start++;
        }
        return ans;
    }
};