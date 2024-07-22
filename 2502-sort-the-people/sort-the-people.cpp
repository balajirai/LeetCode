class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<pair<int, string>>ppl;
        for(int i=0; i<names.size(); i++){
            ppl.push_back({heights[i], names[i]});
        }
        sort(ppl.begin(), ppl.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });

        for(auto p:ppl){
            ans.push_back(p.second);
        }
        return ans;
    }
};