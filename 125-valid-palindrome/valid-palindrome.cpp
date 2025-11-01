class Solution {
public:
    bool palindrom(string s){
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        // Make it lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // Sanitize the given string for alpha numeric
        string str;
        for(char &ch:s){
            if(isalnum(ch)) str +=ch;
        }
        return palindrom(str);
    }
};