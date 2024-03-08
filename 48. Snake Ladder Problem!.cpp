/*
Snake Ladder Problem!
Programming
Graph Data Structure & Algorithms
Medium
49.2% Success

239

10

Bookmark
Asked In:
Problem Description

Rishabh takes out his Snakes and Ladders Game, stares the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

 

 

RULES:

The game is played with cubic dice of 6 faces numbered from 1 to 6.
Starting from 1 , land on square 100 with the exact roll of the die. If moving the number rolled would place the player beyond square 100, no move is made.
If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.
If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.
BOARD DESCRIPTION:

The board is always 10 x 10 with squares numbered from 1 to 100.
The board contains N ladders given in a form of 2D matrix A of size N * 2 where (A[i][0], A[i][1]) denotes a ladder that has its base on square A[i][0] and end at square A[i][1].
The board contains M snakes given in a form of 2D matrix B of size M * 2 where (B[i][0], B[i][1]) denotes a snake that has its mouth on square B[i][0] and tail at square B[i][1].
 
Problem Constraints

1 <= N, M <= 15
*/

int Solution::snakeLadder(vector<vector<int> > &ladder, vector<vector<int> > &snake) {
    // Create maps to store ladder and snake positions
    unordered_map<int, int> snakeMap, ladderMap;
    
    // Populate ladderMap with ladder positions
    for (auto a : ladder) {
        ladderMap[a[0]] = a[1];
    }
    
    // Populate snakeMap with snake positions
    for (auto a : snake) {
        snakeMap[a[0]] = a[1];
    }
    
    // Initialize level, queue for BFS traversal, and visited array
    int level = 0;
    queue<int> q;
    bool visited[101] = {false};
    q.push(1);
    visited[1] = true;
    
    // BFS traversal
    while (!q.empty()) {
        int size = q.size();
        
        while (size--) {
            int currPos = q.front();
            q.pop();
            
            // If current position is the destination (square 100)
            if (currPos == 100) {
                return level;
            }
            
            // Iterate over possible dice rolls (1 to 6)
            for (int i = 1; i <= 6; i++) {
                int nextPos = currPos + i;
                
                // Check if next position is affected by a ladder
                if (ladderMap.find(nextPos) != ladderMap.end()) {
                    nextPos = ladderMap[nextPos];
                }
                // Check if next position is affected by a snake
                else if (snakeMap.find(nextPos) != snakeMap.end()) {
                    nextPos = snakeMap[nextPos];
                }
                
                // If next position is within valid range and not visited, continue traversal
                if (nextPos <= 100 && !visited[nextPos]) {
                    q.push(nextPos);
                    visited[nextPos] = true;
                }
            }
        }
        level++;
    }
    
    // If the destination is unreachable
    return -1;
}
