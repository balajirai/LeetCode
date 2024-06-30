class Solution {
private:
    int solve(vector<int>& coins, int amount, int index, vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(amount < 0 || index >= coins.size()) return 0;

        if(dp[amount][index]!=-1) return dp[amount][index];
        int ans = 0;
        int include = solve(coins, amount-coins[index], index, dp);
        int exclude = solve(coins, amount, index+1, dp);

        return dp[amount][index] = include + exclude;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size()+1, -1));
        return solve(coins, amount, 0, dp);
    }
};