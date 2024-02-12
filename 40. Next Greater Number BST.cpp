/*
Next Greater Number BST
Programming
Tree Data Structure
Easy
47.8% Success

93

9

Bookmark
Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.

If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.

PROBLEM APPROACH:

Complete solution in the hint.
*/

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    stack<TreeNode*> s;
    bool found = false;

    while (A || !s.empty()) {
        // Go to the leftmost node
        while (A) {
            s.push(A);
            A = A->left;
        }

        // Visit the current node
        A = s.top();
        s.pop();

        // If node with value B is found, set found flag
        if (found) {
            return A;
        }
        if (A->val == B) {
            found = true;
        }

        // Move to the right subtree
        A = A->right;
    }

    // If no inorder successor found
    return nullptr;
}
