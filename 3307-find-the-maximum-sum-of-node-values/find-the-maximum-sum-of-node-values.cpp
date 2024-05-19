class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, count = 0, sacrifice = INT_MAX;
        for(auto x:nums){
            if((x^k) > x){
                sum += (x^k);
                sacrifice = min(sacrifice, (long long)((x^k) - x));
                count++;
            }
            else{
                sum += x;
                sacrifice = min(sacrifice, (long long)(x - (x^k)));
            }
        }
        if(count%2 == 0) return sum;
        return sum - sacrifice;
    }
};