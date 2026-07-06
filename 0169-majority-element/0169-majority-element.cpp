class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int count = 0, res = 0;

    for (int n : nums) {
        if (count == 0)        // no candidate
            res = n;           // choose new one

        if (n == res)
            count++;           // vote for candidate
        else
            count--;           // cancel vote
    }
    return res;
}


};