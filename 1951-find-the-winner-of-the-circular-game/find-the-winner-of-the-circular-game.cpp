class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>players(n);
        for(int i=0; i<n; i++) players[i] = i+1;
        int curr = 0;
        while(players.size() > 1){
            int position = (curr + k - 1) % (players.size());
            players.erase(players.begin() + position);
            curr = position;
        }
        return players[0];
    }
};