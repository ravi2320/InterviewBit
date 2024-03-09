/*
Valid Path
Programming
Graph Data Structure & Algorithms
Medium
22.4% Success

184

82

Bookmark
Asked In:
Problem Description
 
 

There is a rectangle with the left top as (0, 0) and the right bottom as (x, y). There are N circles such that their centers are inside the rectangle. The radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :
We can move from any cell to any of its 8 adjacent neighbors and we cannot move outside the boundary of the rectangle at any point of time.
A circle doesn't touch a cell (i,j) if the distance from its center to the cell (i,j) is less than R.


Problem Constraints
0 <= x, y, R <= 100
1 <= N <= 1000
The Center of each circle would lie within the grid


Input Format
1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, the number of circles.
4th argument given is an Integer R, the radius of each circle.
5th argument given is an Array A of size N, where A[i] = x coordinate of the ith circle
6th argument given is an Array B of size N, where B[i] = y coordinate of the ith circle


Output Format
Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).


Example Input
x = 2
y = 3
N = 1
R = 1
A = [2]
B = [3]


Example Output
NO


Example Explanation
There is NO valid path in this case
*/

string Solution::solve(int x, int y, int N, int R, vector<int>& A, vector<int>& B) {
    
    // Create a boolean matrix to represent the grid
    vector<vector<bool>> blocked(x + 1, vector<bool>(y + 1, false));
    
    // Mark cells inside circles as blocked
    for (int i = 0; i < N; ++i) {
        int centerX = A[i], centerY = B[i];
        for (int row = max(0, centerX - R); row <= min(x, centerX + R); ++row) {
            for (int col = max(0, centerY - R); col <= min(y, centerY + R); ++col) {
                if ((centerX - row) * (centerX - row) + (centerY - col) * (centerY - col) <= R * R) {
                    blocked[row][col] = true;
                }
            }
        }
    }
    
    // Implement BFS traversal
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));
    visited[0][0] = true;
    
    while (!q.empty()) {
        int currX = q.front().first, currY = q.front().second;
        q.pop();
        
        if (currX == x && currY == y) {
            return "YES";
        }
        
        // Define eight directions
        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        // Explore adjacent cells
        for (const auto& dir : directions) {
            int newX = currX + dir[0], newY = currY + dir[1];
            if (newX >= 0 && newX <= x && newY >= 0 && newY <= y && !blocked[newX][newY] && !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    return "NO";
}
