class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        vector<int> ans;
        for (int &card:deck) {
            if (!ans.empty()) {
                ans.insert(ans.begin(), ans.back());
                ans.pop_back();
            }
            ans.insert(ans.begin(), card);
        }
        return ans;
    }
};