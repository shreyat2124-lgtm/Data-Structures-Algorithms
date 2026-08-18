class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; int prefix=0,count=0;
        mp[0] = 1;
        for(int i=0;i< nums.size(); i++){
            prefix+= nums[i];

            int need = prefix - k;

            // Check whether we have seen the required previous prefix sum.
            if(mp.find(need) != mp.end()) {
            // If yes, get how many times we saw it and add that many subarrays.
            count += mp[need];
             }

            mp[prefix]++;
     }
         return count;
    }
    
};