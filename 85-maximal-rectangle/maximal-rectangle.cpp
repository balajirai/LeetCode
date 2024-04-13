class Solution {
private:
    vector<int> nextSmaller(vector<int> &arr, int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &arr, int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestArea(vector<int>& heights) {
        int area = INT_MIN, n = heights.size();
        vector<int>next = nextSmaller(heights, n);
        vector<int>prev = prevSmaller(heights, n);

        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i]==-1) next[i] = n;
            int b = next[i] - prev[i] - 1;

            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = INT_MIN;
        vector<int>histogram(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<histogram.size(); j++){
                if(matrix[i][j]=='1') histogram[j]++;
                else histogram[j] = 0;
            }
            maxArea = max(maxArea, largestArea(histogram));
        }
        return maxArea;
    }
};