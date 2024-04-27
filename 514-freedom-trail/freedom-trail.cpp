class Solution {
public:
    int findRotateSteps(string& ring, string& key) {
        vector<int> pos[26];
        const int r = ring.size(), k= key.size();

        // Store the positions of each character in the ring
        for (int i = 0; i < r; i++) {
            pos[ring[i]-'a'].push_back(i);
        }

        // Dynamic programming
        int dp[200][200];
        fill(&(dp[0][0]), &(dp[0][0])+40000, INT_MAX);

        // Start with the first character of the key at position 0
        for (int p : pos[key[0]-'a']) {
            dp[0][p] = min(p, r-p) + 1;
        }
        // Iterate from the start of the key
        for (int i = 1; i < k; i++) {
            // Use nested loop over pos[key[i-1]-'a']*pos[key[i]-'a']
            for (int j: pos[key[i-1]-'a']){
                // Iterate through possible positions and calculate minimum steps
                for (int p : pos[key[i]-'a']) {
                    int step = abs(p-j);
                    step = min(step, r-step);

                    // Update the minimum steps
                    dp[i][p] = min(dp[i][p], dp[i-1][j]+step+1);
                }
            }
        }
        // Return the minimum steps for the last character of the key
        return *min_element(dp[k-1], begin(dp[k-1])+r);
    }
};