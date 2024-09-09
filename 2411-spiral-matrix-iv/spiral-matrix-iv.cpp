class Solution {
private:
    int getValue(ListNode* &head){
        int val = -1;
        if (head){
            val = head->val;
            head = head->next;
        }
        return val;
    }

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int rowStart = 0, colStart = 0;
        int rowEnd = m - 1, colEnd = n - 1;

        vector<vector<int>> ans(m, vector<int>(n, -1));

        while (head && rowStart <= rowEnd && colStart <= colEnd){
            for (int i = colStart; i <= colEnd; i++) {
                ans[rowStart][i] = getValue(head);
            }
            rowStart++;
            for (int i = rowStart; i <= rowEnd; i++) {
                ans[i][colEnd] = getValue(head);
            }
            colEnd--;
            if (rowEnd >= rowStart) {
                for (int i = colEnd; i >= colStart; i--) {
                    ans[rowEnd][i] = getValue(head);
                }
                rowEnd--;
            }

            if (colEnd >= colStart) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    ans[i][colStart] = getValue(head);
                }
                colStart++;
            }
        }
        return ans;
    }
};