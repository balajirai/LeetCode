class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxAns = 1, currentAns = 1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + 1 == nums[i+1]){
                currentAns += 1;
                maxAns = max(maxAns, currentAns);
            }
            else if(nums[i] == nums[i+1]) continue;
            else currentAns = 1;
        }
        return maxAns;
    }
};