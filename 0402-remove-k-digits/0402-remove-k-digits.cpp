class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;
        for (char x : num) {
            while (!st.empty() && k > 0 && st.top() > x) {
                st.pop();
                k--;
            }
            
               if (!st.empty() || x != '0') {
                st.push(x);
            }
            
        }
        //If k > 0 after the loop, we still need to remove digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string m = "";
        while (!st.empty()) {
            m += st.top();
            st.pop();
        }

        reverse(m.begin(), m.end());
        //If the string is empty, return "0", otherwise return m
        return m.empty() ? "0" : m;
    }
};