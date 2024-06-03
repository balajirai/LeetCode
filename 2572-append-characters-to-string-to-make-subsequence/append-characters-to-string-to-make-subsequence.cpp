class Solution {
public:
    int appendCharacters(string s, string t) {
        int sidx = 0, tdix = 0;
        int sLen = s.length(), tLen = t.length();
    
        while (sidx < sLen && tdix < tLen) {
            if (s[sidx] == t[tdix]) {
                tdix++;
            }
            sidx++;
        }
    
        return tLen - tdix;
    }
};