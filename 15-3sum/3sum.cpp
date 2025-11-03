class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Better approach (using set)
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int start = i+1, end = nums.size()-1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    st.insert({nums[i], nums[start], nums[end]});
                    start++, end--;
                }
                else if (sum < 0) start++;
                else end--;
            }
        }
        for(auto &triplet:st) ans.push_back(triplet);
        return ans;
    }
};