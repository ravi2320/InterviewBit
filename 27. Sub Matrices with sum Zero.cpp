/*
Sub Matrices with sum Zero
Programming
Dynamic Programming
Medium
55.7% Success

180

9

Bookmark
Asked In:
Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note:  elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output

2

Explanation

-8 5 7

3 7 -8

5 -8 9

-8 5 7

3 7 -8

5 -8 9
*/

int Solution::solve(vector<vector<int> > &matrix) {
     if (matrix.empty() || matrix[0].empty()) {
        // Handle the case of an empty matrix
        return 0;
    }
    int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++)
            for(int j=1; j<m; j++)
                matrix[i][j] += matrix[i][j-1];
        int answer = 0;
        for(int start = 0; start < m; start++){
            for(int end = start; end < m; end++){
                unordered_map<int, int> hash;
                hash[0] = 1;
                int sum = 0;
                for(int row = 0; row < n; row++){
                    sum += matrix[row][end] - (start > 0 ? matrix[row][start-1]:0);

                    if(hash.find(sum) != hash.end())
                        answer += hash[sum];

                    hash[sum]++; 
                }
            }
        }
        return answer;
}
