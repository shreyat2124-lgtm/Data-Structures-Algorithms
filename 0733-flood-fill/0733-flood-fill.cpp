class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col,
             int oldColor, int newColor)
    {
        // Matrix ke bahar aa gaye.
        if(row < 0 || col < 0 ||
           row >= image.size() ||
           col >= image[0].size())
            return;

        // Sirf wahi cells paint karne hain
        // jo starting cell ke original color ke hain.
        if(image[row][col] != oldColor)
            return;

        // Current cell ko paint kar do.
        image[row][col] = newColor;

        // Ab current cell apne neighbours ko bhi
        // wahi kaam karne ke liye bol raha hai.
        dfs(image, row - 1, col, oldColor, newColor); // Up
        dfs(image, row + 1, col, oldColor, newColor); // Down
        dfs(image, row, col - 1, oldColor, newColor); // Left
        dfs(image, row, col + 1, oldColor, newColor); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        // Starting pixel ka original color yaad rakho.
        int oldColor = image[sr][sc];

        // Agar already isi color ka hai,
        // to kuch bhi change karne ki zarurat nahi.
        if(oldColor == color)
            return image;

        // Starting pixel se flood fill shuru karo.
        dfs(image, sr, sc, oldColor, color);

        // DFS ne image ko reference se modify kar diya hai.
        // Bas wahi modified image return kar do.
        return image;
    
    }
};