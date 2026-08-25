#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_map;
        prefix_map[0] = 1;
        int sum = 0, count = 0;
        
        for (int n : nums) {
            sum += n;
            if (prefix_map.count(sum - k)) {
                count += prefix_map[sum - k];
            }
            prefix_map[sum]++;
        }
        return count;
    }
};