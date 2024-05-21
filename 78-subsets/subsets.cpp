class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_subset = 1<<n;

        vector<vector<int>>power_set;
        for(int mask = 0; mask < total_subset; mask++){
            vector<int>subset;
            for(int i=0; i<n; i++){
                if((mask&(1<<i))!=0) subset.push_back(nums[i]);
            }
            power_set.push_back(subset);
        }
        return power_set;
    }
};