class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftBound = 0;
        int profitTrack = 0;
        for(int rightBound = 1; rightBound < prices.size(); rightBound++){
            if(prices[rightBound] < prices[leftBound]){ // Update the left bound if a lesser buying price is discovered
                leftBound = rightBound;
            }
            profitTrack = max(profitTrack, prices[rightBound] - prices[leftBound]);
        }
        return profitTrack;
    }
}