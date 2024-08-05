class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>freq;
        for(string &str:arr) freq[str]++;
        vector<string>dist;
        for(int i=0; i<arr.size(); i++){
            if(freq[arr[i]] == 1) dist.push_back(arr[i]);
        }
        if(dist.size() < k) return "";
        return dist[k-1];
    }
};