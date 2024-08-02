class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = accumulate(nums.begin(), nums.end(), 0);
        int cnt = accumulate(nums.begin(), nums.begin() + ones, 0);
        int mx = cnt;
        for (int i = ones; i < n + ones; ++i) {
            cnt += nums[i % n] - nums[(i - ones + n) % n];
            mx = max(mx, cnt);
        }
        return ones - mx;
    }
};