#include <vector>
#include <algorithm> // For min()

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        bool hasMinK = false;
        bool hasMaxK = false;

        int startPos = 0;
        long long trackSubArrays = 0;
        int minKPos = 0;
        int maxKPos = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxK || nums[i] < minK){
                hasMinK = false;
                hasMaxK = false;
                startPos = i + 1;
            }
            if(nums[i] == minK){
                hasMinK = true;
                minKPos = i;
            }
            if(nums[i] == maxK){
                hasMaxK = true;
                maxKPos = i;
            }
            if(hasMinK && hasMaxK){
                trackSubArrays += min(minKPos, maxKPos) - startPos + 1;
            } 
        }
        return trackSubArrays;
    }
};