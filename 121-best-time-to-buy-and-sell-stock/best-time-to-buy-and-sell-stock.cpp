class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Better Approach (Two Pointer)
        int maxProf = 0, left = 0, right = 1;
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                int currProf = prices[right] - prices[left];
                maxProf = max(maxProf, currProf);
            }
            else{
                // selling price is less than buying price
                // so make this as buying price and look for greater selling price
                left = right;
            }
            right++;
        }
        return maxProf;
    }
};
