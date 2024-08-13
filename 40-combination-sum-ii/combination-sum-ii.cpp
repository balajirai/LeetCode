class Solution {
private:
    void solve(vector<int>& candidates, vector<int>output, int index, int sum, int target, vector<vector<int>>&ans){
        // base case
        if(sum == target){
            ans.push_back(output);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i]==candidates[i-1]) continue;      // avoiding duplicates
            if(candidates[i] + sum > target ) break;       // no need to go further as we have sorted the candidates array 
            output.push_back(candidates[i]);
            solve(candidates, output, i+1, sum+candidates[i], target, ans);     // recursive call
            output.pop_back();       // backtrack and remove the last added element
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        int sum = 0;
        solve(candidates, output, index, sum, target, ans);
        return ans;
    }
};