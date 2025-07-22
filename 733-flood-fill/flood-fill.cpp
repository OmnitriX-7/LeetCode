class Solution {
public:
    void dfs(vector<vector<int>> &image, int color, int x, int sr, int sc) {
        int m = image.size();
        int n = image[0].size();
        if (sr < 0 || sc < 0 || sr >= m || sc >= n || image[sr][sc] != x) {
            return;
        }
        image[sr][sc] = color;
        dfs(image, color, x, sr+1, sc);
        dfs(image, color, x, sr-1, sc);
        dfs(image, color, x, sr, sc+1);
        dfs(image, color, x, sr, sc-1);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color != image[sr][sc]){
            dfs(image, color, image[sr][sc], sr, sc);
        }
        return image;
    }
};