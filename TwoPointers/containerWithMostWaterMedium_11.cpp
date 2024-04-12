class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftBound = 0;
        int rightBound = height.size() - 1;
        int area = 0, maxArea = 0;
        while(leftBound < rightBound){
            area = min(height[rightBound], height[leftBound]) * (rightBound - leftBound);
            maxArea = max(maxArea, area);
            if(height[rightBound] > height[leftBound]){
                leftBound++;
            }
            else if(height[rightBound] < height[leftBound]){
                rightBound--;
            }
            else{
                rightBound--;
            }
        }
        return maxArea;
    }
};