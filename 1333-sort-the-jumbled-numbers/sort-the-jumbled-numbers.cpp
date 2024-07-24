class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>temp;
        for(int &num:nums){
            string str1 = to_string(num), str2 = "";
            for(char &ch:str1){
                int ind = ch - '0';
                int val = mapping[ind];
                str2 += to_string(val);
            }
            int newNum = stoi(str2);
            temp.push_back({newNum, num});
        }
        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        };

        stable_sort(temp.begin(), temp.end(), comparator);

        vector<int>ans;
        for(auto &p:temp){
            ans.push_back(p.second);
        }
        return ans;
    }
};