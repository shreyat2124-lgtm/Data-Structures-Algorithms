class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        unordered_set<char> inStack;
        stack<char> st;
        
        for (char c : s) {
            count[c]++;
        }
        
        for (char c : s) {
            // Decrement the count because we are currently processing it
            count[c]--;
            
            // If it's already in our stack, we don't need it again
            if (inStack.count(c)) {
                continue;
            }
            
            // Pop elements that are larger AND still appear later in the string
            while (!st.empty() && st.top() > c && count[st.top()] > 0) {
                inStack.erase(st.top()); // Remove from set
                st.pop();                // Remove from stack
            }
            
            // Push the current character and mark it as in the stack
            st.push(c);
            inStack.insert(c);
        }
        
        // Build the final string
        string m = "";
        while (!st.empty()) {
            m += st.top();
            st.pop();
        }
        reverse(m.begin(), m.end());
        
        return m;
    }
};