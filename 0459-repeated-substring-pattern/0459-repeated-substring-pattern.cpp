class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

    // try every possible starting length
    for (int len = 1; len < n; len++) {

        // take the first 'len' characters
        string startPart = s.substr(0, len);

        string formed = "";

        // keep adding startPart
        while (formed.length() < n) {
            formed += startPart;
        }

        // check if we recreated the string
        if (formed == s) {
            return true;
        }
    }

    return false;
}
    
};