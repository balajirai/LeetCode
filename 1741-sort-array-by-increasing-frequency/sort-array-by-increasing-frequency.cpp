class Solution {
private:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int &x:nums) freq[x]++;
        
        vector<pair<int, int>> elements;
        for (auto& entry : freq) {
            elements.push_back(entry);
        }

        sort(elements.begin(), elements.end(), cmp);

        vector<int> ans;
        for (auto& element : elements) {
            for (int i = 0; i < element.second; i++) {
                ans.push_back(element.first);
            }
        }

        return ans;
    }
};