class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeTaken = 0;
        for(int i = 0; i < tickets.size(); i++){
            if( i <= k ){
                timeTaken += min(tickets[i], tickets[k]);
            }
            else{
                timeTaken += min(tickets[i], tickets[k]-1);
            }
        }
        return timeTaken;
    }
};