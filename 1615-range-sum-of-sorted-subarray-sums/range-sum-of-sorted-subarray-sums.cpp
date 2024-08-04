class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // brute force
        vector<int>sums;
        for (int start = 0; start < n; ++start){
            for (int end = start; end < n; ++end){
                int sum = 0;
                for (int k = start; k <= end; ++k){
                    sum += nums[k];
                }
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        left = left-1, right = right-1;
        int ans = 0, MOD = 1e9+7;
        for(int i=left; i<=right; i++){
            ans = (ans + sums[i]) % MOD;
        }
        return ans;
    }
};