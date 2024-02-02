/*
Path in Directed Graph
Programming
Graph Data Structure & Algorithms
Easy
52.2% Success

183

21

Bookmark
Asked In:
Problem Description

Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

NOTE:

There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



Output Format
Return 1 if path exists between node 1 to node A else return 0.



Example Input
Input 1:

 A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]
Input 2:

 A = 5
 B = [  [1, 2]
        [2, 3] 
        [3, 4] 
        [4, 5] ]


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation*
Explanation 1:

 The given doens't contain any path from node 1 to node 5 so we will return 0.
Explanation 2:

 Path from node1 to node 5 is ( 1 -> 2 -> 3 -> 4 -> 5 ) so we will return 1.
*/


int isPath(int src, int dist, vector<int> adjList[], vector<bool> &visited){
    visited[src] = true;
    
    for(int child : adjList[src]){
        if(child == dist) 
            return 1;
        
        if(!visited[child] && isPath(child, dist, adjList, visited))
            return 1;
    }
    return 0;
}
int Solution::solve(int n, vector<vector<int>> &edge) {
    vector<int> adjList[n+1];
    vector<bool> visited(n+1, false);
    for(int i=0; i<edge.size(); i++){
        int u = edge[i][0];
        int v = edge[i][1];
        adjList[u].push_back(v);
    }

    return isPath(1, n, adjList, visited);
}

