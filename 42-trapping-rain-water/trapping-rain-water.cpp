class Solution {
public:
    int trap(vector<int>& height) {
        // optimal solution using two pointer
        int n = height.size();
        int ans = 0;
        int left = 0, right = n-1;
        int leftmax = 0, rightmax = 0;

        while(left<=right){
            if(height[left] <= height[right]){
                if(height[left] >= leftmax) leftmax = height[left];
                else ans += (leftmax-height[left]);
                left++;
            }
            else{
                if(height[right] >= rightmax) rightmax = height[right];
                else ans += (rightmax-height[right]);
                right--;
            }
        }
        return ans;
    }
};