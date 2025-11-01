class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Better appraoch
        vector<int>ans;
        vector<int>vec;
        
        // case 1 : No zeros present
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                vec.push_back(i);
                continue;
            }
            res *= nums[i];
        }
        if(vec.size() > 1) return vector<int>(nums.size(), 0);
        else if(vec.size() == 1){
            ans = vector<int>(nums.size(), 0);
            ans[vec[0]] = res;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                ans.push_back(res/nums[i]);
            }
        }
        return ans;
    }
};