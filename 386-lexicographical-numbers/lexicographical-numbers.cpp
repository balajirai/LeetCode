class Solution {
private:
    void solve(int num, vector<int>& list, int &n) {
        if (num > n) return;
        list.push_back(num); 
        for (int i = 0; i <= 9; i++) {
            int newInt = num * 10 + i;
            if (newInt > n) return;
            solve(newInt, list, n);
        }
    }
    
public:
    vector<int> lexicalOrder(int n) {       
        vector<int> list;
        for (int i = 1; i <= 9; i++){
            solve(i, list, n);
        }
        return list;
    }
};