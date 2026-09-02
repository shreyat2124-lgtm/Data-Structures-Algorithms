class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<char,int>need;map<char,int>window;
        int left=0,right=0;
        // Count characters we need from s1
        for(int i = 0; i < s1.size(); i++) {
            need[s1[i]]++;
        }

        for(right=0;right<s2.size();right++){
            window[s2[right]]++;

            if(right-left+1>s1.size()){
                window[s2[left]]--;
                // Remove character completely if its count becomes 0.
                if(window[s2[left]] == 0) 
                    window.erase(s2[left]);

                left++;
            }

            if(window==need)
            return true;
        }
        return false;
    }
};