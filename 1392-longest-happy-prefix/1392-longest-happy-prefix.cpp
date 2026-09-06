class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i <= r)
                z[i] = min(r-i+1, z[i-l]);
            while(i + z[i] < n &&
                  s[z[i]] == s[i+z[i]]) {
                z[i]++;
            }
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        int best = 0;
        for(int i = 1; i < n; i++) {
            if(i + z[i] == n) {
                best = max(best, z[i]);
            }
        }

        return s.substr(0, best);
    }
};