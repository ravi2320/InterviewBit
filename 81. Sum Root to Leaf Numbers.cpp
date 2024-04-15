/*
Sum Root to Leaf Numbers
Programming
Tree Data Structure
Medium
30.7% Success

220

207

Bookmark
Asked In:
Problem Description
 
 

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers % 1003.


Problem Constraints
0 <= Node.val <= 9


Input Format
The first argument is TreeNode A, pointing to the root of the tree.


Output Format
Return an integer equal to the total sum of all root-to-leaf numbers % 1003.


Example Input
    1
   / \
  2   3


Example Output
25


Example Explanation
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

*/

/*
Intuition:
- We traverse the binary tree in a depth-first manner.
- At each node, we compute the number formed by the path from the root to that node.
- We maintain a running sum and update it with the numbers formed by each root-to-leaf path.
- Finally, we return the sum modulo 1003 as required.

Time Complexity: O(N)
- We visit each node of the binary tree once.

Space Complexity: O(H)
- The space complexity is determined by the recursion stack.
- In the worst case, the height of the binary tree is equal to the number of nodes, resulting in O(N) space complexity.
*/

int solve(TreeNode* root, int curr, int mod){
    // Base case: if the current node is NULL, return 0
    if(!root)
        return 0;
        
    // Update the current number formed by appending the current node's value
    curr = ((curr % mod) * 10 + root->val) % mod;
    
    // If the current node is a leaf, return the current number
    if(!root->left && !root->right)
        return curr;
    
    // Recursively compute the sum of root-to-leaf numbers for the left and right subtrees
    int l = solve(root->left, curr, mod);
    int r = solve(root->right, curr, mod);
    
    // Return the sum of root-to-leaf numbers for the current subtree
    return (l + r) % mod;
}

int Solution::sumNumbers(TreeNode* A) {
    int mod = 1003; // Define the modulo value
    // Call the recursive function to compute the sum of root-to-leaf numbers
    return solve(A, 0, mod);
}
