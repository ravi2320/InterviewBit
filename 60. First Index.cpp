/*
First Index
Programming
Binary Search
Very Easy
59.1% Success

8

23

Bookmark
Problem Description

You are given an array A of length N. You need to solve Q queries. In each query, you will be given an integer B[i] and you need to find the index of the element which is at least B[i]. If there are several such indexes, return the minimum such index. Return -1 if no such index exists.

Note- The array is 0 indexed.



Problem Constraints
1 <= N,Q <= 5 x 105 

1 <= A[i], B[i] <= 109



Input Format
The first argument contains an integer array A of length N.

The second argument contains an integer array B of length Q, denoting the queries.



Output Format
Return an array of length Q, containing the answer to the queries.

f


Example Input

  Input 1:

  A : [ 9, 1 ]
  B : [ 7, 10, 3 ]
Input 2:
   A : [ 2, 3, 4 ]
  B : [ 2, 3, 4 ]


Example Output

  Output 1:

  [0, -1, 0]
Output 2:
  [0, 1, 2]


Example Explanation

  Explanation 1:

  The first element 9 is greater than 7 and 3. No element greater than 10 exists.
Explanation 2:
  Since the queries and array are same, the answer will the index of the element.
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int q = B.size();
    vector<int> ans(q, -1);
    for(int i = 0; i < q; i++) {
        for(int j = 0; j < A.size(); j++) {
            if(B[i] <= A[j]){ // Changed condition to handle equal elements
                ans[i] = j;
                break;
            }
        }
    }
    return ans;
}
