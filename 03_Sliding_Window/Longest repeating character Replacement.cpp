#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int max_count = 0;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'A']++;
            max_count = max(max_count, count[s[right] - 'A']);
            
            // Current window size minus the most frequent character 
            // gives the number of replacements needed.
            // If it exceeds k, we must shrink the window.
            while ((right - left + 1) - max_count > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};