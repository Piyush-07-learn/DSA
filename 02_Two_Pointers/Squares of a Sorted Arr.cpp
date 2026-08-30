#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        
        for (int p = n - 1; p >= 0; p--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[p] = nums[left] * nums[left];
                left++;
            } else {
                result[p] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};