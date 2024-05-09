class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq (happiness.begin(), happiness.end());
        long long ans = pq.top(), count = 1; pq.pop();
        while(count < k){
            if((pq.top()-count) > 0){
                ans += (pq.top()-count);
                pq.pop();
                count++;
            }
            else break;
        }
        return ans;
    }
};