class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays){
        int mini = 1e5, maxi = -1e5, diff = 0;
        for(auto& arr: arrays){
            int first=arr[0], last=arr.back();
            diff = max({diff, last-mini, maxi-first});
            mini = min(first, mini);
            maxi = max(last, maxi);
        }
        return diff;
    }
};