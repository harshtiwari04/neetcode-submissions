class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            // 1. If it's an opening bracket, push it onto the stack
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            } 
            // 2. If it's a closing bracket, validate it
            else {
                // If the stack is empty, there's no matching opening bracket
                if (st.empty()) return false;
                
                // Check if the top of the stack matches the current closing bracket
                if ((s[i] == ']' && st.top() != '[') ||
                    (s[i] == '}' && st.top() != '{') ||
                    (s[i] == ')' && st.top() != '(')) {
                    return false; 
                }
                
                // If it matches, safely pop it
                st.pop();
            }
        }
        
        // If the stack is empty, all brackets were matched perfectly
        return st.empty();
    }
};