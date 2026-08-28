#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sorting is required for the Two Pointer approach
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    // Skip duplicate elements for the second number to avoid duplicate triplets
                    while (left < right && nums[left] == nums[left-1]) left++; 
                }
            }
        }
        return result;
    }
};