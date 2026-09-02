class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,ans=0,maxfreq=0;
        unordered_map<char,int>mp;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            maxfreq=max(maxfreq,mp[s[right]]);
             while((right - left + 1) - maxfreq > k)
              {
             mp[s[left]]--;
             left++;
             }

    ans = max(ans, right - left + 1);
}
return ans;    
    }
};