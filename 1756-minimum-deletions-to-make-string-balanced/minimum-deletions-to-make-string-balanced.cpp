class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>leftb(s.size()), righta(s.size());
        int aCount = 0, bCount = 0;
        for(int i=0; i<s.size(); i++){
            leftb[i] = bCount;
            if(s[i] =='b') bCount++;
        }

        for(int i=s.size()-1; i>=0; i--){
            righta[i] = aCount;
            if(s[i] == 'a') aCount++;
        }

        int ans = INT_MAX;
        for(int i=0; i<s.size(); i++){
            ans = min(ans, leftb[i]+righta[i]);
        }

        return ans;
    }
};