class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Better Solution
        unordered_map<int,int>hash;
        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            // Agar mil jata hai
            if(hash.find(second) != hash.end()){
                return {i, hash[second]};
            }

            // Agar ni milta hai
            hash[first] = i;

        }
        return {};
    }
};