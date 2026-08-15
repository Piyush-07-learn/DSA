#include 
#include 
#include 

using namespace std;

class Solution {
public:
    vector twoSum(vector& nums, int target) {
        unordered_map numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If the complement exists in our map, we found the pair
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};