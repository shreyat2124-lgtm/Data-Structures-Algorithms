class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        long ans = 0;
        long num = 0;
        long sign = 1;
        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '+') {
                ans += sign * num;
                num = 0;
                sign = 1;
            }

            else if (s[i] == '-') {
                ans += sign * num;
                num = 0;
                sign = -1;
            }

            else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                ans += sign * num;
                num = 0;

                int oldSign = st.top();
                st.pop();
                int oldAns = st.top();
                st.pop();

                ans = oldAns + oldSign * ans;
            }
        }
        ans += sign * num;
        return ans;
    }
};