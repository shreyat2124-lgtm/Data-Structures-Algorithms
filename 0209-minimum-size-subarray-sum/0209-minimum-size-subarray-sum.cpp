class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0; int minl=INT_MAX; unordered_set<int> st; int sum=0;

        for(right=0;right<nums.size();right++){
        st.insert(nums[right]);
        sum+=nums[right];

        while(sum>=target){
        minl=min(minl,right-left+1);
        st.erase(nums[left]);
        sum -= nums[left];
        left++;
        }
        
        }
        if(minl == INT_MAX)
        return 0;
        return minl;
    }

};