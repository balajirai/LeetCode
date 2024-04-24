class Solution {
    vector<int>series{0,1,1};
public:
    int tribonacci(int n) {
        if(n < series.size()) return series[n];
        while(n >= series.size()){
            int k = series.size();
            series.push_back(series[k-1] + series[k-2] + series[k-3]);
        }
        return series[n];
    }
};