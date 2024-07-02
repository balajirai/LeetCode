class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;      // element -> count
        for(int &a:nums1) mp[a]++;
        for(int b:nums2){
            if(mp.count(b) > 0){
                ans.push_back(b);
                mp[b]--;
                if(mp[b]==0) mp.erase(b);
            }
        }
        return ans;
    }
};