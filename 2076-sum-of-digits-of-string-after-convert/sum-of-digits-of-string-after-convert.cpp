class Solution {
private:
    string digit_sum(string num){
        int temp = 0;
        for(int i=0; i<num.size(); i++){
            temp += (num[i] - '0');
        }
        return to_string(temp);
    }
public:
    int getLucky(string s, int k) {
        string num = "";
        for(int i=0; i<s.size(); i++){
            string tmp = to_string(s[i] - 'a' + 1);
            num += tmp;
        }
        cout << num << endl;
        string ans = "";
        while(k--){
            ans = digit_sum(num);
            num = ans;
        }
        cout << ans << endl;

        return stoi(ans);
    }
};