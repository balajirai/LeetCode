class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>hash;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        vector<pair<int,int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            return a.second > b.second;
        });

        for(auto &p:vec){
            if(k-- > 0) ans.push_back(p.first);
            else break;
        }
        return ans;
    }
};