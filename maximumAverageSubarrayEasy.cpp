class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int leftBound = 0;
        double averageTrack = INT_MIN;
        double windowSum = 0.0;

        for(int rightBound = 0; rightBound < nums.size(); rightBound++){
            windowSum += nums[rightBound];
            if((rightBound - leftBound + 1) == k){
                averageTrack = max(averageTrack, (double)windowSum/(double)k);
                windowSum -= nums[leftBound++];
            }
        }
        return averageTrack;
    }
};