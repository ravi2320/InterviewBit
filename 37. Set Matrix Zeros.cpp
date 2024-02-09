/*
Set Matrix Zeros
Programming
Arrays
Easy
30.3% Success

302

26

Bookmark
Asked In:
Problem Description
 
 

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Problem Constraints
1 <= N, M <= 1000
0 <= A[i][j] <= 1


Input Format
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.


Output Format
Return a 2-d matrix that satisfies the given conditions.


Example Input
Input 1:
[   [1, 0, 1],
    [1, 1, 1], 
    [1, 1, 1]   ]
Input 2:
[   [1, 0, 1],
    [1, 1, 1],
    [1, 0, 1]   ]


Example Output
Output 1:
[   [0, 0, 0],
    [1, 0, 1],
    [1, 0, 1]   ]
Output 2:
[   [0, 0, 0],
    [1, 0, 1],
    [0, 0, 0]   ]
*/

class Solution {
public:
    void markColumn(int col, vector<vector<int>> &matrix){
        for(int i = 0; i < matrix.size(); i++) { // Loop through rows
            matrix[i][col] = -1; // Mark the cell in the current row and the specified column
        }
    }
    
    void markRow(int row, vector<vector<int>> &matrix){
        for(int j = 0; j < matrix[0].size(); j++) { // Loop through columns
            matrix[row][j] = -1; // Mark the cell in the specified row and the current column
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0){
                    markRow(i, matrix);
                    markColumn(j, matrix);
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};


//Better Solution
//Time Complexity : O(2 * n * m)
//Space Complexity : O(n + m)
class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


