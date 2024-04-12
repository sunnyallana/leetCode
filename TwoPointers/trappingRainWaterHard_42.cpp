class Solution {
public:
    int trap(vector<int>& height) {
        int leftBound = 0, rightBound = height.size() - 1;
        int maxLeft = height[leftBound], maxRight = height[rightBound];
        int waterStored = 0;

        while(leftBound < rightBound){
            if(maxLeft > maxRight){
                rightBound--;
                maxRight = max(maxRight, height[rightBound]);
                waterStored += maxRight - height[rightBound];
            
            }
            else{
                leftBound++;
                maxLeft = max(maxLeft, height[leftBound]);
                waterStored += maxLeft - height[leftBound];
            }
        }
        return waterStored;
    }
};