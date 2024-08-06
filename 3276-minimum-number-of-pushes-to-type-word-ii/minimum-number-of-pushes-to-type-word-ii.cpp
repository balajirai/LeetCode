class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0); int result = 0;
        for(char &ch:word) mp[ch-'a']++;
        sort(mp.begin(), mp.end(), greater<int>());     // descending order frequency
        for(int i=0; i<26; i++){
            int freq = mp[i];
            int press = i/8 + 1;
            result += freq * press;
        }
        return result;
    }
};