#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {
            // Find the next valid character in string s
            while (i >= 0) {
                if (s[i] == '#') { skipS++; i--; }
                else if (skipS > 0) { skipS--; i--; }
                else break;
            }
            // Find the next valid character in string t
            while (j >= 0) {
                if (t[j] == '#') { skipT++; j--; }
                else if (skipT > 0) { skipT--; j--; }
                else break;
            }
            
            // Compare valid characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            // If one string is exhausted and the other is not
            if ((i >= 0) != (j >= 0)) return false;
            
            i--; j--;
        }
        return true;
    }
};