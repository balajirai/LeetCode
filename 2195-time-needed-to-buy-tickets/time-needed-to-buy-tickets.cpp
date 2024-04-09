class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<int>dq;
        for(int i=0; i<tickets.size(); i++){
            dq.push_back(i);
        }
        int time = 0;
        while(!dq.empty()){
            int frontIdx = dq.front();
            dq.pop_front();
            if(tickets[frontIdx]){
                time++;
                tickets[frontIdx]--;
                if(tickets[frontIdx]) dq.push_back(frontIdx);
            }
            if(frontIdx == k && tickets[frontIdx] == 0){
                return time;
            }
        }
        return 0;
    }
};