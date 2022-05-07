class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        // iterate through the grid and for each position in the row and column run a dfs 
        int r = NULL;
        while(r < board.size()) 
        {
            int c = NULL;
            while(c < board[0].size()) 
            {
                if(depthFirstSearch(board, word, 0, r, c)) // if the dfs returns true, then the function should return true
                {
                    return true;
                }
                
                c++;
            }
            r++;
        }
        
        return false;
    }
    
    bool depthFirstSearch(vector<vector<char>>& board, string word, int start, int r, int c) {
        if(start == word.length()) return true; // base case
        
        // if out of bounds then its invalid 
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[start]) return false; 
        
        char tmp = board[r][c];
        board[r][c] = '*';
        
        // recursively run dfs on all four adjacent positions 
        bool res = (depthFirstSearch(board, word, start + 1, r - 1, c) || depthFirstSearch(board, word, start + 1, r + 1, c) || depthFirstSearch(board, word, start + 1, r, c - 1) || depthFirstSearch(board, word, start + 1, r, c + 1));
        board[r][c] = tmp;
        
        return res;
    }
};