class Solution {
public:

    int longestConsecutive(vector<int>& nums)
    {
        // Store every number.
        // HashSet gives O(1) lookup.
        unordered_set<int> st;

        for(int x : nums)
        {
            st.insert(x);
        }

        int longest = 0;

        // Check every unique number.
        for(int x : st)
        {
            // Start counting only if
            // this number is the beginning
            // of a sequence.
            if(st.find(x-1) == st.end())
            {
                int curr = x;
                int len = 1;

                // Keep moving forward
                // while next consecutive
                // number exists.
                while(st.find(curr+1) != st.end())
                {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};