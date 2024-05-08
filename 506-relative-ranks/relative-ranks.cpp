class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> maxHeap;
        for(int i=0; i<score.size(); i++){
            maxHeap.push({score[i], i});
        }
        vector<string>rank(score.size()); int pos = 0;
        string arr[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        while(!maxHeap.empty()){
            auto [scr, i] = maxHeap.top();
            maxHeap.pop();
            if(pos < 3) rank[i] = arr[pos];
            else rank[i] = to_string(pos+1);
            pos++;
        }
        return rank;
    }
};