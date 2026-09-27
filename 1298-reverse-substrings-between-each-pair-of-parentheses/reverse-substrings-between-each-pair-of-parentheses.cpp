class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(result.size());
            }
            else if(ch == ')'){
                int l = st.top();
                st.pop();
                reverse(result.begin()+l, result.end());
            }
            else result += ch;
        }
        return result;
    }
};