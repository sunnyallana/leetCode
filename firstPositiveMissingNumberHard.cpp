/*

FIRST POSITIVE MISSING NUMBER

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1

*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};


/*
Clean the array: We want to ignore numbers that are not useful for us. So, we go through our list (nums) one by one.If a number is zero or negative, or if it's greater than m (our total number of elements), we consider it not useful and replace it with zero. This simplifies our task because we only care about positive integers up to m.

Put numbers to their place using cyclic sort i.e swap until you find the number : (This works because of Pigeonhole Principle) : The Pigeonhole Principle states that if you have more "pigeons" than "pigeonholes," at least one pigeonhole must contain more than one pigeon. In this context:

The "pigeons" are the positive integers from 1 to m (where m is the size of the input array nums).

The "pigeonholes" are the indices of the array nums.

The goal in this problem is to find the first missing positive integer. If there are no missing positive integers in the range from 1 to m, then all the pigeons are already in their correct pigeonholes, and no pigeonhole contains more than one pigeon.

So Now, we want to arrange the remaining positive integers in the correct order from 1 to m. We do this using a technique called cyclic sort.

We go through our list again, and for each number: If it's not zero (useful) and not already in the right place (not equal to i + 1), we swap it with the number in its rightful position, which is nums[i] - 1. We repeat this until we can't swap anymore.

Finding the First Missing Positive:

Once we've sorted our list, we go through it one more time to find the first number that's not in its expected position.

The first missing positive integer is equal to i + 1 (because we're looking for the number that should be in the i-th position of our sorted list).

If we don't find any missing positive integers in the range from 1 to m, we return m + 1, indicating that all positive integers up to m are present in the list.

*/