/*
Pascal Triangle
Programming
Arrays
Easy
51.7% Success

182

27

Bookmark
Asked In:
Problem Description
 
 

Given an integer A, equal to numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from the previous row R - 1.



Problem Constraints
0 <= A <= 25


Input Format
The first argument is an integer A, equal to the numRows.


Output Format
Return an array of array of integers, equal to pascal triangle.


Example Input
A = 5


Example Output
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> pascalTriangle;
    for(int row = 1; row <= A; row++){
        pascalTriangle.push_back(generateRow(row));
    }
    return pascalTriangle;
}
