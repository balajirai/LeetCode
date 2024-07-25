class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int &num:nums) mp[num]++;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int>ans;
        for(int num=mini; num<=maxi; num++){
            while(mp[num] > 0){
                ans.push_back(num);
                mp[num]--;
            }
        }

        return ans;
    }
};