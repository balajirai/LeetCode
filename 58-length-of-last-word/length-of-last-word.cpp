class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int start = 0, end = 0;
        while(end < s.size()){
            if(s[end] == ' ') start = end+1;
            else ans = end - start + 1;
            end++;
        }
        return ans;
    }
};