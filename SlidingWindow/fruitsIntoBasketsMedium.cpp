#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> trees;
        int maxFruits = 0;
        int leftBound = 0;

        for (int rightBound = 0; rightBound < fruits.size(); rightBound++) {
            // Update the frequency of the current fruit
            trees[fruits[rightBound]]++;

            // Shrink the window until we have only 2 types of fruits
            while (trees.size() > 2) {
                // Decrease the frequency of the fruit at the left bound
                trees[fruits[leftBound]]--;
                // If the frequency becomes 0, remove it from the map
                if (trees[fruits[leftBound]] == 0) {
                    trees.erase(fruits[leftBound]);
                }
                // Move the left bound to the right
                leftBound++;
            }

            // Update the maximum number of fruits
            maxFruits = max(maxFruits, rightBound - leftBound + 1);
        }

        return maxFruits;
    }
};
