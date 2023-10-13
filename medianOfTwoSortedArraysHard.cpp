/*
MEDIAN OF TWO SORTED ARRAYS

Given two sorted arrays nums1and nums2 of size mand n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log(m + n)).



Example 1:

Input: nums1 = [1, 3], nums2 = [2]
Output : 2.00000
Explanation : merged array = [1, 2, 3] and median is 2.
Example 2 :

    Input : nums1 = [1, 2], nums2 = [3, 4]
    Output : 2.50000
    Explanation : merged array = [1, 2, 3, 4] and median is(2 + 3) / 2 = 2.5.


    Constraints :

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    - 106 <= nums1[i], nums2[i] <= 106

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            mergedArray.push_back(nums2[j]);
            j++;
        }

        int sizeMerged = mergedArray.size();
        int mid = sizeMerged / 2;

        if (sizeMerged % 2 == 0) {
            return (double)(mergedArray[mid - 1] + mergedArray[mid]) / 2.0;
        }
        else {
            return (double)mergedArray[mid];
        }
    }
};