class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Treat the entire matrix
        // as one sorted array.

        int low = 0;
        int high = m*n - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            // Convert 1D index
            // back into matrix coordinates.

            int row = mid / n;
            int col = mid % n;

            // Found the target.
            if(matrix[row][col] == target)
            {
                return true;
            }

            // Target lies ahead.
            else if(matrix[row][col] < target)
            {
                low = mid + 1;
            }

            // Target lies behind.
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};