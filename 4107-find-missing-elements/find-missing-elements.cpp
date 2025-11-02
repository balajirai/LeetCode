class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int start = nums[0], end = nums[nums.size()-1];
        int i = 0;
        while(start < end && i < nums.size()){
            if(start != nums[i]){
                ans.push_back(start);
            }
            else i++;
            start++;
        }
        return ans;
    }
};