class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int start = customers[0][0], end = start + customers[0][1];
        double total_waiting_time = end-start;
        for(int i=1; i<customers.size(); i++){
            if(customers[i][0] <= end){
                start = end;
                cout << start << endl;
                end = start + customers[i][1];
            }
            else{
                start = customers[i][0];
                end = start + customers[i][1];
            }
            total_waiting_time += (end - customers[i][0]);
        }
        double avg_waiting_time = total_waiting_time/(customers.size());
        return avg_waiting_time;
    }
};