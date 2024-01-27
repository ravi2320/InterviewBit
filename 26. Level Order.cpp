/*
Level Order
Programming
Graph Data Structure & Algorithms
Easy
76.3% Success

134

16

Bookmark
Asked In:
Problem Description
 
 

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



Problem Constraints
 1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(A==NULL) return {};
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(A);
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> temp;
        for(int i=0; i<levelSize; i++){
            TreeNode* front = q.front();
            q.pop();
            
            temp.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
