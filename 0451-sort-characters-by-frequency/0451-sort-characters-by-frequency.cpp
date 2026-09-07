class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
         string ans = "";
        while (!mp.empty()) {
            char maxChar;
            int maxFreq = 0;
            
            for (auto x : mp) {
                if (x.second > maxFreq) {
                    maxChar = x.first;
                    maxFreq = x.second;
                }
            }
            // Add it maxFreq times
            for (int i = 0; i < maxFreq; i++) {
                ans += maxChar;
            }
            mp.erase(maxChar);
        }

        return ans;
    }
};