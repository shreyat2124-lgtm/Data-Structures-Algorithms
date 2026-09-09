class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> bestAnswer;
        
        //  taking i digits from nums1
        for (int i = 0; i <= k; i++) {
            int j = k - i; //  remaining 'j' digits from nums2
            
            // check enough digits in both arrays for this split
            if (i <= nums1.size() && j <= nums2.size()) {
                
                vector<int> part1 = getBestDigits(nums1, i);
                vector<int> part2 = getBestDigits(nums2, j);
                vector<int> candidate = merge(part1, part2);
                
                
                if (bestAnswer.empty() || candidate > bestAnswer) {
                    bestAnswer = candidate;
                }
            }
        }
        
        return bestAnswer;
    }

private:
    // Get the largest possible sequence (monotonic stack) 
    vector<int> getBestDigits(vector<int>& nums, int count) {
        vector<int> st;
        int drop =nums.size()-count;
        
        for (int num : nums) {
            
            while (st.size() > 0 && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }
        
        // chop off the extra digits at the end
        while (st.size() > count) {
            st.pop_back();
        }
        
        return st;
    }
    
    // Combine two sequences to make the biggest possible number
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0; 
        int j = 0;
        
        while (i < nums1.size() || j < nums2.size()) {
            if (isFirstBigger(nums1, i, nums2, j)) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        return result;
    }
    
    // Check which array has the bigger remaining numbers
    bool isFirstBigger(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        // Skip past matching numbers to find the first difference
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        
        
        if (j == nums2.size()) return true;
        if (i == nums1.size()) return false;
        
        // compare the first digit that was different
        return nums1[i] > nums2[j];
    }
};