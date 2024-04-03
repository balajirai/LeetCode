class Solution {
private:
    bool ans = false;
    bool isSafe(vector<vector<char>>& board, string &word, int x, int y, int m, int n, int idx){
        if((x>=0 && y>=0) && (x<m && y<n) && (board[x][y]==word[idx])) return true;
        else return false;
    }
    void solve(vector<vector<char>>& board, string output, int x, int y, int m, int n, int idx, string &word){
        // base case
        if(output == word){
            ans = true;
            return;
        }

        if(idx >= word.size() || x >= m || y >= n){
            return;
        }

        // 4 choices Top right bottom left

        // TOP
        int newx = x-1;
        int newy = y;

        if(isSafe(board, word, newx, newy, m, n, idx)){
            char c = board[newx][newy];     
            output.push_back(c);
            board[newx][newy] = '#';   // visited
            solve(board, output, newx, newy, m, n, idx+1, word);
            output.pop_back();    // backtrack
            board[newx][newy] = c;
            
        }

        // RIGHT
        newx = x;
        newy = y+1;

        if(isSafe(board, word, newx, newy, m, n, idx)){
            char c = board[newx][newy];     
            output.push_back(c);
            board[newx][newy] = '#';   // visited
            solve(board, output, newx, newy, m, n, idx+1, word);
            output.pop_back();         // backtrack
            board[newx][newy] = c;
            
        }

        // BOTTOM
        newx = x+1;
        newy = y;

        if(isSafe(board, word, newx, newy, m, n, idx)){
            char c = board[newx][newy];     
            output.push_back(c);
            board[newx][newy] = '#';   // visited
            solve(board, output, newx, newy, m, n, idx+1, word);
            output.pop_back();    // backtrack
            board[newx][newy] = c;
        }

        // LEFT
        newx = x;
        newy = y-1;

        if(isSafe(board, word, newx, newy, m, n, idx)){
            char c = board[newx][newy];     
            output.push_back(c);
            board[newx][newy] = '#';   // visited
            solve(board, output, newx, newy, m, n, idx+1, word);
            output.pop_back();    // backtrack
            board[newx][newy] = c;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string output;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    int srcx = i;
                    int srcy = j;
                    int idx = 0;
                    output.push_back(word[0]);
                    board[i][j] = '#'; 
                    solve(board, output, srcx, srcy, m, n, idx+1, word);
                    output.pop_back();
                    board[i][j] = word[0]; 
                }
            }
        }

        return ans;
    }
};