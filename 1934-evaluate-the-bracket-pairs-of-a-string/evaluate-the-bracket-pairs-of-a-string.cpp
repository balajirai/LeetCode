class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        // first take the key value in map
        unordered_map<string,string>m;
        for(int i=0; i<knowledge.size(); i++){
            m[knowledge[i][0]] = knowledge[i][1];
        }

        string result = "";
        int index = 0, n = s.size();
        while(index < n){
            if(s[index] == '('){
                index++;
                string temp = "";
                while(s[index] != ')'){
                    temp += s[index];
                    index++;
                }
                if(m.count(temp) > 0) result += m[temp];
                else result += '?';
                index++;
                continue;
            }
            else {
                result += s[index];
                index++;
            }
        }

        return result;
    }
};