#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate area: width * min height of the two lines
            int current_water = min(height[left], height[right]) * (right - left);
            max_water = max(max_water, current_water);
            
            // Move the pointer that limits the height
            if (height[left] < height[right]) left++;
            else right--;
        }
        return max_water;
    }
};