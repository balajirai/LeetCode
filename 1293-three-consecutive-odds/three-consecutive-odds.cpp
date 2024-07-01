class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            int count = 0;
            for(int j=i; j<i+3 && j<arr.size(); j++){
                if(arr[j] & 1) count++;
                else count = 0;
            }
            if(count == 3) return true;
        }
        return false;
    }
};