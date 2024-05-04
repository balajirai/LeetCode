class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start = 0, end = people.size()-1, ans = 0;
        while(start <= end){
            if(people[end] + people[start] <= limit){
                start++, end--;
            }
            else  end--;
            ans++;
        }
        return ans;
    }
};