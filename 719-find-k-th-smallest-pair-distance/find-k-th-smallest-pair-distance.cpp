class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // brute force
        vector<int>arr;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int dist = abs(nums[i]-nums[j]);
                arr.push_back(dist);
            }
        }
        nth_element(arr.begin(), arr.begin() + (k-1), arr.end());
        return arr[k-1];
    }
};