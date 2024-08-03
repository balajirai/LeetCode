class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!= arr.size()) return false;
        unordered_map<int,int>mp;
        for(int &num:target) mp[num]++;
        for(int &num:arr) mp[num]--;
        for(auto &num:mp){
            if(mp[num.first] > 0) return false;
        }
        return true;
    }
};