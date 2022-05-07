class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = NULL; // variable to keep track of # of islands
        
        // iterate through each row and column of the grid 
        int r = NULL;
        while (r < grid.size()) 
        {
            int c = NULL;
            while(c < grid[0].size())
            {
                // if an island is found add 1 to number of islands found, and run bfs
                // to check if there are neighbor islands horizontally and vertically
                if(grid[r][c] == '1') 
                {
                    numOfIslands = numOfIslands + 1;
                    breadthFirstSearch(grid, r, c); //bfs
                }
                c++;
            }
            r++;
        }
        return numOfIslands; // total # of islands 
    }
    
    void breadthFirstSearch(vector<vector<char>>& grid, int r, int c) {
        
        if (r <  0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1') return; // base case
        
        grid[r][c] = '0';
        breadthFirstSearch(grid, r+1, c); // recursively check the right side of 1
        breadthFirstSearch(grid, r-1, c); // recursively check the left side of 1 
        breadthFirstSearch(grid, r, c+1); // recursively check below 1 
        breadthFirstSearch(grid, r, c-1); // recursively check above 1

        
        
    }
};