class Solution {
public:
    bool isAnagram(string s, string t) {
        // better
        unordered_map<char, int>letter;
        for(auto &ch:s) letter[ch]++;
        for(auto &ch:t) letter[ch]--;
        for(auto &ch:letter){
            if(ch.second) return false;
        }
        return true;
    }
};