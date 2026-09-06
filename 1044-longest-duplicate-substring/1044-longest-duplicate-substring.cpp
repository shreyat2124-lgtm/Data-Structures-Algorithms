class Solution {
public:
    int check(string& s, int len) {

        long long base = 31;
        long long mod = 1000000007;

        long long hash = 0;
        long long power = 1;

        unordered_map<long long, int> mp;

        // First window
        for (int i = 0; i < len; i++) {
            hash = (hash * base + s[i]) % mod;
        }

        // base^(len-1)
        for (int i = 1; i < len; i++) {
            power = (power * base) % mod;
        }

        mp[hash] = 0;

        // Slide window
        for (int i = len; i < s.size(); i++) {

            // Remove left
            hash = (hash - s[i - len] * power % mod + mod) % mod;

            // Add right
            hash = (hash * base + s[i]) % mod;

            // Duplicate found
            if (mp.find(hash) != mp.end()) {
                int old = mp[hash];
                if (s.substr(old, len) == s.substr(i - len + 1, len))
                    return old;
            }
            
            mp[hash] = i - len + 1;
        }

        return -1;
    }

    string longestDupSubstring(string s) {

        int left = 1;
        int right = s.size() - 1;

        int ans = 0;
        int start = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            int pos = check(s, mid);

            if (pos != -1) {

                // Duplicate exists
                ans = mid;
                start = pos;

                // Try bigger
                left = mid + 1;
            } else {

                // No duplicate
                // Try smaller
                right = mid - 1;
            }
        }

        if (ans == 0)
            return "";

        return s.substr(start, ans);
    }
};