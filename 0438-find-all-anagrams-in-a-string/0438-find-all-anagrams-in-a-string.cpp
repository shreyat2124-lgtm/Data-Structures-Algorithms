class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int>need;map<char,int>window;
        int left=0,right=0;
        // Count characters we need from p
        for(int i = 0; i < p.size(); i++) {
            need[p[i]]++;
        }

        for(right=0;right<s.size();right++){
            window[s[right]]++;

            if(right-left+1>p.size()){
                window[s[left]]--;
                // Remove character completely if its count becomes 0.
                if(window[s[left]] == 0) 
                    window.erase(s[left]);

                left++;
            }

            if(window==need)
            ans.push_back(left);
        }
        return ans;
    }
};

