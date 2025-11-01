class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Better appraoch
        vector<int>ans;
        vector<int>zeros;
        
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeros.push_back(i);
                continue;
            }
            res *= nums[i];
        }
        // Case1: Two or more Zeros
        if(zeros.size() > 1) return vector<int>(nums.size(), 0);

        // Case2 : Only one Zero
        else if(zeros.size() == 1){
            ans = vector<int>(nums.size(), 0);
            ans[zeros[0]] = res;
        }

        // Case3 : No Zeros
        else{
            for(int i=0; i<nums.size(); i++){
                ans.push_back(res/nums[i]);
            }
        }
        return ans;
    }
};