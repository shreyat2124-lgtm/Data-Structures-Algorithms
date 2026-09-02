class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> st;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.length(); right++) {

        // if duplicate found, shrink window from left
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        // add current character
        st.insert(s[right]);

        // update max length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
    }
};