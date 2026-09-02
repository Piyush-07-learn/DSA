#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);
        
        // Populate the frequency of the first window
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1_count[i] == s2_count[i]) matches++;
        }
        
        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            if (matches == 26) return true;
            
            // Add right character to the window
            int index = s2[right] - 'a';
            s2_count[index]++;
            if (s2_count[index] == s1_count[index]) matches++;
            else if (s2_count[index] == s1_count[index] + 1) matches--;
            
            // Remove left character from the window
            index = s2[left] - 'a';
            s2_count[index]--;
            if (s2_count[index] == s1_count[index]) matches++;
            else if (s2_count[index] == s1_count[index] - 1) matches--;
            
            left++;
        }
        
        return matches == 26;
    }
};