/*
Distribute Candy
Programming
Greedy Algorithm
Medium
55.4% Success

427

22

Bookmark
Asked In:
Problem Description
 
 

N children are standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum number of candies you must give?



Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109




Input Format
The first and only argument is an integer array A representing the rating of children.



Output Format
Return an integer representing the minimum candies to be given.



Example Input
Input 1:

 A = [1, 2]
Input 2:

 A = [1, 5, 2, 1]


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 The candidate with 1 rating gets 1 candy and candidate with rating 2 cannot get 1 candy as 1 is its neighbor. 
 So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.
Explanation 2:

 Candies given = [1, 3, 2, 1]
*/

/*
Intuition:
- We initialize a dynamic programming (DP) array 'dp' of size 'n', where 'dp[i]' represents the number of candies assigned to the i-th child.
- First, we traverse the input array 'A' from left to right and update 'dp' such that 'dp[i]' is incremented by 1 compared to 'dp[i-1]' if 'A[i]' is greater than 'A[i-1]'. This ensures that a child with a higher rating receives more candies than the previous child.
- Next, we traverse the input array 'A' from right to left and update 'dp' again to handle cases where a child with a higher rating needs more candies than the next child.
- Finally, we sum up all elements of 'dp' to get the total number of candies distributed.

Time Complexity: O(N)
- We traverse the input array twice, once from left to right and once from right to left, each taking O(N) time.

Space Complexity: O(N)
- We use a DP array of size 'n', where 'n' is the number of elements in the input array.
*/

int Solution::candy(vector<int> &A) {
        int n = A.size();
        vector<int> dp(n, 1); // Initialize DP array with 1 for each child
        
        // Traverse from left to right
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i - 1])
                dp[i] = dp[i - 1] + 1; // Increment candies if child's rating is higher
        }
        
        // Traverse from right to left
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] > A[i + 1])
                dp[i] = max(dp[i], dp[i + 1] + 1); // Update candies if necessary for next child
        }
        
        // Calculate total number of candies
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += dp[i];
        }
        
        return ans;
}
