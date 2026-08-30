class Solution {
public:
    int getMaxLen(vector<int>& nums) {

        int pos = 0;
        int neg = 0;
        int ans = 0;
        for(int x : nums) {
            if(x == 0) {
                // 0 makes the product 0.
                // So start a completely new subarray.
                pos = 0;
                neg = 0;
            }

            else if(x > 0) {
                // Positive keeps the sign the same.
                pos++;
                if(neg > 0)
                    neg++;
            }

            else {
                // Negative flips the sign.
                int oldPos = pos;
                int oldNeg = neg;
                // Old positive becomes negative.
                neg = oldPos + 1;
                // Old negative becomes positive.
                if(oldNeg > 0)
                    pos = oldNeg + 1;
                else
                    pos = 0;
                // The current negative number itself
                // can always form a negative subarray.
                if(neg == 0)
                    neg = 1;
            }

            ans = max(ans, pos);
        }

        return ans;
    }
};