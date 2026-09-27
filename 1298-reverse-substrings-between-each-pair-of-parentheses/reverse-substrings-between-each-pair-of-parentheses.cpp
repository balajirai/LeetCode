class Solution {
public:
    string reverseParentheses(string s) {
        
        // Wormhole Teleportation Technique

        int n = s.size();
        stack<int>open_bracktes;
        vector<int>wormhole(n);

        // Phase 1: Construct the wormhole teleportation map
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open_bracktes.push(i);  // open bracket index
            else if(s[i] == ')'){
                int j = open_bracktes.top();   // last open bracket index (for this closing bracket)
                open_bracktes.pop();
                wormhole[i] = j;
                wormhole[j] = i;   // Link both ends of the wormhole
            }
        }

        // Phase 2: Traverse and teleport
        string result = "";
        int direction = 1; // 1 = forward, -1 = backward

        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = wormhole[i];        // Teleport to the matching bracket
                direction = -direction; // Reverse the scanning direction
            }
            else {
                result += s[i];         // Add normal characters directly
            }
        }

        return result;
    }
};