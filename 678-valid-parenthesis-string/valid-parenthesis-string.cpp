class Solution {
private:
    bool solve(int index, int open, string &s, vector<vector<int>>&dp){
        if(index == s.size()) return open == 0;

        if(dp[index][open] != -1) return dp[index][open];

        bool isValid = false;

        // case 1 : '*'
        if(s[index] == '*'){
            // option 1 : open
            isValid |= solve(index+1, open+1, s, dp);

            // option 2 : empty ""
            isValid |= solve(index+1, open, s, dp);

            // option 3 : close
            if(open > 0){
                isValid |= solve(index+1, open-1, s, dp);
            }
        }
        // case 2 : '('
        else if(s[index] == '('){
            isValid |= solve(index+1, open+1, s, dp);
        }
        // case 3 : ')'
        else if(open > 0){
            isValid |= solve(index+1, open-1, s, dp);
        }

        return dp[index][open] = isValid;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, 0, s, dp);
    }
};