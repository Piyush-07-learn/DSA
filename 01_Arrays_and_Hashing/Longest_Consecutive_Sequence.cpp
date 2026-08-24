#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        
        for (int num : numSet) {
            // Only start checking if it's the beginning of a sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Count upwards
                while (numSet.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                longest = std::max(longest, currentStreak);
            }
        }
        
        return longest;
    }
};