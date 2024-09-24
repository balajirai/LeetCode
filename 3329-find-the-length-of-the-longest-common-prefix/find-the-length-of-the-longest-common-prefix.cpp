class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        set<string>st;
        for(int i=0; i<n; i++){
            string num = to_string(arr1[i]);
            string s = "";
            for(char &ch:num){
                s += ch;
                st.insert(s);
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            string num = to_string(arr2[i]);
            string s = "";
            for(char &ch:num){
                s += ch;
                if(st.count(s)){
                    ans = max(ans, (int)s.size());
                }
            }
        }
        return ans;
    }
};