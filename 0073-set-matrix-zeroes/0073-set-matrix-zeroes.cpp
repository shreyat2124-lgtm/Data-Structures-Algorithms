class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> cols;
        vector<int> rows;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    cols.push_back(j);
                    rows.push_back(i);
                }
            }
        }
        for(auto& col:cols) {
            for(int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
        for(auto& row:rows) {
            for(int i = 0; i < n; i++) {
                matrix[row][i] = 0;
            }
        }
    }
};