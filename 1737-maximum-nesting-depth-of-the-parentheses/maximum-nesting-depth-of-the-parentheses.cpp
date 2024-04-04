class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int opened = 0, maxi=0;
        for(auto &c:s){
            if(c == '(') opened++, maxi = max(maxi, opened);
            else if(c == ')') opened--;
        }
        return maxi;
    }
};