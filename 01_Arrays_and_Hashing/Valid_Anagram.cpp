#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;
        
        std::vector<int> count(26, 0);
        
        // Increment for string s, decrement for string t
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // If they are anagrams, every counter should be exactly 0
        for (int c : count) {
            if (c != 0) return false;
        }
        
        return true;
    }
};