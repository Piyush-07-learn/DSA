#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        
        for (std::string s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end()); // Sort the string to create the key
            anagramMap[key].push_back(s);      // Group original string under this key
        }
        
        std::vector<std::vector<std::string>> result;
        for (auto pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};