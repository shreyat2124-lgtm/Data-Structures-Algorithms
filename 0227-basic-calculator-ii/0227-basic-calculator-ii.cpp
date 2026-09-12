class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long currentNumber = 0;
        char op = '+';

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }

            if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {
                if (op == '+') {
                    st.push(currentNumber);
                } else if (op == '-') {
                    st.push(-currentNumber);
                } else if (op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * currentNumber);
                } else if (op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / currentNumber);
                }

                op = ch;
                currentNumber = 0;
            }
        }

        int totalSum = 0;
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }

        return totalSum;
    }
};