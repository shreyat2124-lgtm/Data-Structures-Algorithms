class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
           // Left is already supposed to be EVEN
            if(nums[left] % 2 == 0) {
                left++;
            }

            // Right is already supposed to be ODD
            else if(nums[right] % 2 != 0) {
                right--;
            }

            // left = ODD and right = EVEN
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return {nums};
    }
};