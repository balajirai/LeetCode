class Solution {
private:
    int dp[1001][1001];
    int solve(int i, int remWidth, int maxHeight, int shelfWidth, vector<vector<int>>& books){
        if(i >= books.size()) return maxHeight;

        if(dp[i][remWidth]!=-1) return dp[i][remWidth];

        int width = books[i][0], height = books[i][1];
        int keep = INT_MAX, skip = INT_MAX;

        // keep in current shelf
        if(width <= remWidth){
            keep = solve(i+1, remWidth-width, max(maxHeight, height), shelfWidth, books);
        }

        // skip and put in next shelf
        skip = maxHeight + solve(i+1, shelfWidth-width, height, shelfWidth, books);

        return dp[i][remWidth] = min(keep, skip);
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, shelfWidth, 0, shelfWidth, books);
        return ans;
    }
};