class Solution {
public:
    int maxArea(vector<int>& height) {
        // Better approach
        int maxAmount = 0;
        int left = 0, right = height.size()-1;
        while(left < right){
            int minHeight = min(height[left], height[right]);
            int width = right-left;
            int currAmount = minHeight*width;
            maxAmount = max(maxAmount, currAmount);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxAmount;
    }
};