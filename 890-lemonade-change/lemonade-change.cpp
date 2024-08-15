class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]!=5){
                if(bills[i] == 10){
                    if(five) five--;
                    else return false;
                    ten++;
                }
                else{
                    if(ten && five) ten--, five--;
                    else if(five >= 3) five -= 3; 
                    else return false;
                }
            }
            else five++;
        }
        return true;
    }
};