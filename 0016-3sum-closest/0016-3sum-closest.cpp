class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int ans= nums[0]+nums[1]+nums[3];
       
        for(int i=0; i< nums.size()-1;i++){
            int left=i+1,right=nums.size()-1;
            while(left < right){
            sum= nums[i]+nums[left]+nums[right];

            if(sum==target)
                return sum;
            if(abs(sum - target) < abs(ans - target))
                ans = sum;
            else if(sum<target)
             left++;
            else if(sum>target)
             right--;

            }
        }
       return ans;
    }
};