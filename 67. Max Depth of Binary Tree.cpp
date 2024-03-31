/*
Max Depth of Binary Tree
Programming
Tree Data Structure
Medium
72.6% Success

219

11

Bookmark
Asked In:
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
max depth = 2.
*/

/*
Intuition:
- This function calculates the maximum depth of a binary tree recursively.
- If the current node is NULL, it means it's a leaf node or an empty subtree, so its depth is 0.
- Otherwise, we recursively compute the depth of the left and right subtrees.
- The depth of the current node is 1 plus the maximum of the depths of its left and right subtrees.
- The maximum depth of the binary tree is the depth of the root node.

Time Complexity: O(N)
- We traverse each node in the binary tree exactly once, so the time complexity is linear with respect to the number of nodes in the tree.

Space Complexity: O(H)
- The space complexity is proportional to the height of the binary tree, as the recursion depth can be at most equal to the height of the tree.
*/

int Solution::maxDepth(TreeNode* node) {
    // If the current node is NULL, its depth is 0
    if (node == NULL)
        return 0;

    // Recursively compute the depth of the left and right subtrees
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    // Return the maximum depth of the current node's left and right subtrees plus 1
    return 1 + max(lDepth, rDepth);
}

/*
Intuition:
- This function calculates the maximum depth of a binary tree iteratively using breadth-first search (BFS).
- It performs level order traversal starting from the root node.
- At each level, it increments a counter to keep track of the current depth.
- Once all nodes at each level have been visited, the final value of the counter represents the maximum depth of the binary tree.

Time Complexity: O(N)
- We traverse each node in the binary tree exactly once during the level order traversal, resulting in linear time complexity with respect to the number of nodes in the tree.

Space Complexity: O(W)
- The space complexity is proportional to the maximum width (number of nodes at the widest level) of the binary tree.
- In the worst case, the entire last level of the tree may be stored in the queue, leading to space complexity equal to the width of the tree.

*/

int Solution::maxDepth(TreeNode* node) {
    // If the current node is NULL, its depth is 0
    if (node == NULL)
        return 0;

    int depth = 0;
    queue<TreeNode*> q;
    q.push(node);
    
    // Perform level order traversal
    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level
        // Process all nodes at the current level
        for (int i = 0; i < size; ++i) {
            TreeNode* temp = q.front();
            q.pop();
            // Enqueue the left and right children of the current node, if any
            if (temp->left) 
                q.push(temp->left);
            if (temp->right) 
                q.push(temp->right);
        }
        // Increment the depth for each level processed
        depth++;
    }
    
    return depth;
}
