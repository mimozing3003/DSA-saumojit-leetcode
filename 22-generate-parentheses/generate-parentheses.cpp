#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open, int close, int max_n) {
        if (current.length() == max_n * 2) {
            result.push_back(current);
            return;
        }
        
        if (open < max_n) {
            backtrack(result, current + "(", open + 1, close, max_n);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max_n);
        }
    }
};