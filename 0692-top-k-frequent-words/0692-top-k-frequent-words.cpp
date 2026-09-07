class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string s : words)
            mp[s]++;

        vector<string> ans;
        while(ans.size() < k) {
            string maxs;
            int maxf = 0;
            for(auto x : mp) {
                if(x.second > maxf || (x.second == maxf && x.first < maxs)) {
                    maxs = x.first;
                    maxf = x.second;
                }
            }
            ans.push_back(maxs);
            mp.erase(maxs);
        }
        return ans;
    }
};