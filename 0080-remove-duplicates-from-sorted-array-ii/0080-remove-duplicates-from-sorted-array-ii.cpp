class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    int slow = 0;
    int count = 0;

    for(int fast = 0; fast < nums.size(); fast++) {

        if(fast == 0 || nums[fast] != nums[fast - 1])
            count = 1;
        else
            count++;

        if(count <= 2) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}
};
    
