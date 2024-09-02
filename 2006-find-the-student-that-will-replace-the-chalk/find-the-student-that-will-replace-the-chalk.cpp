class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0, index = 0;
        for(int i=0; i<chalk.size(); i++){
            sum += chalk[i];
        }
        k = k % sum;
        while(k > 0 && k >= chalk[index]){
            k -= chalk[index++];
        }
        return index;
    }
};