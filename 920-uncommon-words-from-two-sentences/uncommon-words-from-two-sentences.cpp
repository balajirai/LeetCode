class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2, word = "";
        unordered_map<string,int> freq;
        for(char &ch : s){
            if(ch == ' '){
                freq[word]++;
                word = "";
            }
            else word += ch;
        }
        
        // last word
        if(word != ""){
            freq[word]++;
            word = "";
        }

        vector<string> ans;
        for(auto& element:freq){
            if(element.second==1){
                ans.emplace_back(element.first);               
            }
        }
        return ans;
    }
};