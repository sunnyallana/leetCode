#include <vector>
#include <unordered_map>

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        unordered_map<int, int> studentPreferences;

        // Count the number of students preferring each type of sandwich
        for (int student : students) {
            studentPreferences[student]++;
        }

        // Simulate students taking sandwiches based on preferences
        for (int i = 0; i < n; i++) {
            int currentSandwich = sandwiches[i];

            if (studentPreferences[currentSandwich] == 0) {
                // No more students can eat this type of sandwich
                return n - i;  // Remaining students unable to eat
            }

            // The student at the front of the queue takes the sandwich
            studentPreferences[currentSandwich]--;
        }

        // If all students can take sandwiches, return 0
        return 0;
    }
};
