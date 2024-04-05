/*
Hotel Service
Programming
Stacks And Queues
Medium
49.0% Success

121

12

Bookmark
Asked In:
Problem Description
 
 

You are travelling to Neverland. After a long journey, you decided to take rest in a hotel for a night.

You have the map of Neverland in the form of 2D matrix A with dimensions N x M. 

The rows are numbered from 1 to N, and the columns are numbered from 1 to M.

You can travel from one cell to any adjacent cell. Two cells are considered adjacent if they share a side.

In the map, there are only two digits, 0 and 1, 
where 1 denotes a hotel in that cell, and 0 denotes an empty cell.

You are also given another 2D array B with dimension Q x 2,
 
where each row denotes a co-ordinate (X, Y) on the map (1 - indexed). 
For each coordinate you have to find the distance to the nearest hotel.

Return an array denoting the answer to each coordinate in the array B.



**Problem Constraints**
1 <= N, M <= 103
1 <= Q <= 105
0 <= A[i][j] <= 1
1 <= B[i][0] <= N
1 <= B[i][1] <= M
There is guranteed to be atleast one hotel on the map.


**Input Format**
The first argument is the 2D integer array A.
The second argument is the 2D integer array B.


**Output Format**
Return an integer array denoting the answer to each coordinate in the array B.


**Example Input**
Input 1:
A = [[0, 0],
     [1, 0]]
B = [[1, 1],
     [2, 1],
     [1, 2]]
Input 2:

A = [[1, 0, 0 1]]
B = [[1, 2],
     [1, 3]]


**Example Output**
Output 1:
[1, 0, 2]
Output 2:

[1, 1]


**Example Explanation**
Explanation 1:
(1, 1) is adjacent to a hotel. (2, 1) has a hotel. (1, 2) is two cells away from the hotel on (2, 1).
Explanation 2:

(1, 2) is adjacent to a hotel on (1, 1). (1, 3) is adjacent to a hotel on (1, 4).
*/

/* 
Intuition:
- We use BFS to find the shortest distance from each hotel to all reachable coordinates on the map.
- Then, we calculate the distances for each coordinate in B based on the precomputed distances.

Time Complexity: O(N*M) where N is the number of rows and M is the number of columns in the map A.
- We traverse the entire map A to find hotel coordinates, which takes O(N*M) time.
- We perform BFS, which can visit each cell at most once, leading to a time complexity of O(N*M).

Space Complexity: O(N*M) for the distance matrix.
- We use a 2D distance matrix to store the shortest distances from each hotel to all reachable coordinates.
- Hence, the space complexity is O(N*M).

*/

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size(), m = A[0].size();
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<int> result;

    // Initialize queue for BFS
    queue<pair<int, int>> q;

    // Push all hotel coordinates to the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    // Perform BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Check all four adjacent cells
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Check if the adjacent cell is within bounds and unvisited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Calculate distances for each coordinate in B
    for (auto coord : B) {
        int x = coord[0] - 1;
        int y = coord[1] - 1;
        result.push_back(dist[x][y]);
    }

    return result;
}
