class Solution {
public:
    int strStr(string haystack, string needle) {
    int i = 0, j = 0;
    int start = 0;
    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) {
            if (j == 0) start = i;   // remember where match started
            i++;
            j++;
            if (j == needle.size())
                return start;       // full needle matched
        } else {
            if (j > 0) {
                i = start + 1;      // restart from next position
                j = 0;
            } else {
                i++;
            }
        }
    }
    return -1;
}

    
};