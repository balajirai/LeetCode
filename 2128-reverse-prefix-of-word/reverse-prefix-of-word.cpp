class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto found = word.find(ch);
        if(found != string::npos){
            reverse(word.begin(), word.begin()+found+1);
        }
        return word;
    }
};