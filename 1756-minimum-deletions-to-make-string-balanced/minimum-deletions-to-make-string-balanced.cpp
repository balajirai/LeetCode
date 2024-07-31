class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()){
                if(st.top() == 'b' && s[i] == 'a'){
                    count++;
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        return count;
    }
};