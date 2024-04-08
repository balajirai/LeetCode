class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0, square = 0;
        for(int i=0; i<students.size(); i++){
            if(students[i] == 0) circular++;
            else square++;
        }

        for(int i=0; i<sandwiches.size(); i++){
            if(sandwiches[i] == 0){
                if(circular > 0) circular--;
                else return square;
            }
            else{
                if(square > 0) square--;
                else return circular;
            }
        }
        return 0;
    }
};