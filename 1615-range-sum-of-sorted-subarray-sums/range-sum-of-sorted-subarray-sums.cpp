class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarraySums, prefixSums(n + 1, 0);
        int MOD = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                subarraySums.push_back(prefixSums[end + 1] - prefixSums[start]);
            }
        }
        sort(subarraySums.begin(), subarraySums.end());

        int result = 0;
        left -= 1, right -= 1;
        for (int i = left; i <= right; ++i) {
            result = (result + subarraySums[i]) % MOD;
        }

        return result;
    }
};