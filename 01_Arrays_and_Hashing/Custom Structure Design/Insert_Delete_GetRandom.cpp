#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> valToIndex;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) return false;
        int lastElement = nums.back();
        int idx = valToIndex[val];
        
        nums[idx] = lastElement;
        valToIndex[lastElement] = idx;
        
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};