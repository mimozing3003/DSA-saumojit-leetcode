#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Start by assuming the first string is the common prefix
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // While the current string doesn't start with the prefix
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by 1 from the end
                prefix = prefix.substr(0, prefix.length() - 1);
                // If the prefix becomes empty, there is no common prefix
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};