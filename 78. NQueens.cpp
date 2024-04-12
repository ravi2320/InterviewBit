/*
NQueens
Programming
Backtracking
Hard
39.3% Success

242

13

Bookmark
Asked In:
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,

There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/*
Intuition:
- The N-Queens problem is solved using backtracking.
- We define a recursive function `solve` to place queens on the chessboard.
- At each column, we iterate through each row and try to place a queen.
- We check if the current position is valid by ensuring that no other queen threatens it.
- We maintain vectors `leftRow`, `lowerDiagnol`, and `upperDiagnol` to keep track of occupied rows and diagonals.
- If a valid position is found, we recursively explore the next column.
- Once all columns are filled, we add the current configuration of the board to the answer vector.

Time Complexity: O(N!)
- In the worst-case scenario, where all possible configurations of queens are explored, the time complexity is factorial, O(N!).

Space Complexity: O(N^2)
- The space complexity is O(N^2) due to the board configuration and auxiliary vectors.
*/

void solve(int col, vector<vector<string>> &ans, vector<string> &board, 
           vector<int> &leftRow, vector<int> &lowerDiagnol, vector<int> &upperDiagnol, int n) {
    
    // Base case: All columns filled, add current board configuration to answer
    if (col == n) {
        ans.push_back(board);
        return;
    }
    
    // Try placing queen in each row of current column
    for (int row = 0; row < n; row++) {
        // Check if position is valid
        if (leftRow[row] == 0 && lowerDiagnol[row + col] == 0 && upperDiagnol[n - 1 + col - row] == 0) {
            // Place queen and update auxiliary vectors
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagnol[row + col] = 1;
            upperDiagnol[n - 1 + col - row] = 1;
            
            // Recur to next column
            solve(col + 1, ans, board, leftRow, lowerDiagnol, upperDiagnol, n);
            
            // Backtrack: Remove queen and reset auxiliary vectors
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagnol[row + col] = 0;
            upperDiagnol[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.')); // Initialize board with empty squares
    vector<int> leftRow(n, 0), upperDiagnol(2 * n - 1, 0), lowerDiagnol(2 * n - 1, 0); // Initialize auxiliary vectors
    solve(0, ans, board, leftRow, lowerDiagnol, upperDiagnol, n); // Start recursive backtracking
    return ans;
}
