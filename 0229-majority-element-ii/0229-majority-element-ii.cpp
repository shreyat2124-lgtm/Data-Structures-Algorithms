class Solution {
public:

    vector<int> majorityElement(vector<int>& nums)
    {
        int cnt1 = 0;
        int cnt2 = 0;

        int ele1 = 0;
        int ele2 = 0;

        // STEP 1
        // Find two possible majority candidates.

        for(int n : nums)
        {
            // Candidate 1 is empty.
            if(cnt1 == 0 && n != ele2)
            {
                ele1 = n;
                cnt1 = 1;
            }

            // Candidate 2 is empty.
            else if(cnt2 == 0 && n != ele1)
            {
                ele2 = n;
                cnt2 = 1;
            }

            // Vote for candidate 1.
            else if(n == ele1)
            {
                cnt1++;
            }

            // Vote for candidate 2.
            else if(n == ele2)
            {
                cnt2++;
            }

            // Current number supports neither.
            // Cancel one vote from both.
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        // STEP 2
        // Verify both candidates, check their actual frequency

        cnt1 = 0;//reset the votes, now we will find the frequency.
        cnt2 = 0;

        for(int n : nums)
        {
            if(n == ele1)
            {
                cnt1++;
            }
            else if(n == ele2)
            {
                cnt2++;
            }
        }

        vector<int> ans;

        if(cnt1 > nums.size()/3)
        {
            ans.push_back(ele1);
        }

        if(cnt2 > nums.size()/3)
        {
            ans.push_back(ele2);
        }

        return ans;
    }
};