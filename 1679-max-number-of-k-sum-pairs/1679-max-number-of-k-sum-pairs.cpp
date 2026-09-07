class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int x : nums) {
            int need = k - x;

            // lookup need
            if(mp.find(need)!=mp.end()&& mp[need] > 0){
                ans++;
                mp[need]--;
            }
            else
            mp[x]++;
            // if found:
                // make pair
                // decrease/remove need
                // ans++
            // otherwise store x
        }

        return ans;
    }
};