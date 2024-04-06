class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0; i<s.size(); i++){
            if(!isalpha(s[i])){
                if(!st.empty() && st.top().first == '(' && s[i] == ')'){
                    st.pop();
                }
                else st.push({s[i], i});
            }
        }

        while(!st.empty()){
            int i = st.top().second;
            cout << st.top().first << " : " << st.top().second <<endl;
            st.pop();
            s.erase(i, 1);
        }
        return s;
    }
};