class Solution {
public:
    int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left < right) {

        // If left wall is smaller,water at the left side depends on leftMax.
        if(height[left] <= height[right]) {

            // Update the tallest wall seen from the left
            leftMax = max(leftMax, height[left]);

            // If current wall is shorter than leftMax,the difference is water trapped here.
            water += leftMax - height[left];

            // Move toward the middle
            left++;
        }

        else {

            // Update the tallest wall seen from the right
            rightMax = max(rightMax, height[right]);

            // If current wall is shorter than rightMax,the difference is water trapped here.
            water += rightMax - height[right];

            // Move toward the middle
            right--;
        }
    }

    return water;

    }
};