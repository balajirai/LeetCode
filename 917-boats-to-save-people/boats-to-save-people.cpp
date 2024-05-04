class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start = 0, end = people.size()-1, ans = 0;
        while(start <= end){
            if(start == end){
                ans++;
                break;
            }
            else if(people[end] + people[start] <= limit){
                ans++;
                start++, end--;
            }
            else{
                ans++;
                end--;
            }

        }
        return ans;
    }
};