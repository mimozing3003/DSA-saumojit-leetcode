#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If the stack is empty, there is no matching opening bracket
                if (st.empty()) {
                    return false;
                }
                
                // Get the most recent opening bracket
                char top = st.top();
                
                // Check if the current closing bracket matches the top of the stack
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // It's a match, remove it from the stack
                } else {
                    return false; // Mismatched brackets
                }
            }
        }
        
        // If the stack is empty, all brackets were properly closed
        return st.empty();
    }
};