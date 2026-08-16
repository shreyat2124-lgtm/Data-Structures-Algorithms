class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int left=0; int count=0; int mul=1; unordered_set<int> st;
        for(int right=0;right<nums.size();right++){
            mul*=nums[right];
            st.insert(nums[right]);
           
            while(mul>=k && left <= right){
                st.erase(nums[left]);
                mul/=nums[left];
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
};