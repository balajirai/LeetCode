class Solution {
public:
    bool isAnagram(string s, string t) {
        // First approach in mind
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};