/*
Convert Sorted List to Binary Search Tree
Programming
Graph Data Structure & Algorithms
Medium
56.4% Success

190

4

Bookmark
Asked In:
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3

Show similar questions
File Search
27 Minutes Medium
Asked in:
Sum Of Fibonacci Numbers
53 Minutes Medium
Asked in:
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.
submission-count
29502
successful submissions.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Function to find the middle node of a singly-linked list.
 * It returns the middle node and disconnects the list from the middle.
 * @param head Pointer to the head of the list.
 * @return Pointer to the middle node.
 */
 
 /**
 * Function to convert a sorted linked list to a binary search tree.
 * Algorithm:
 * 1. Base case: If the input linked list is empty, return NULL.
 * 2. Find the middle node of the linked list using the slow and fast pointer technique.
 * 3. Create a new tree node with the value of the middle node.
 * 4. If the middle node is the only node in the list, return the root node.
 * 5. Recursively build the left subtree of the binary search tree using the nodes to the left of the middle node.
 * 6. Recursively build the right subtree of the binary search tree using the nodes to the right of the middle node.
 * 7. Return the root of the binary search tree.
 * @param A Pointer to the head of the sorted linked list.
 * @return Pointer to the root of the binary search tree.
 */
 
ListNode* middle(ListNode *head){
    ListNode *prev = NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    
    // Traverse the list with two pointers, one moving one step at a time,
    // and the other moving two steps at a time.
    // When the fast pointer reaches the end, the slow pointer will be at the middle.
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Disconnect the list from the middle node.
    if(prev)
        prev->next = NULL;
    
    return slow;
}
 
/**
 * Function to convert a sorted linked list to a binary search tree.
 * @param A Pointer to the head of the sorted linked list.
 * @return Pointer to the root of the binary search tree.
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Base case: if the list is empty, return NULL.
    if(!A) return NULL;
    
    // Find the middle node of the list.
    ListNode* middleNode = middle(A);
    
    // Create a new tree node with the value of the middle node.
    TreeNode *root = new TreeNode(middleNode->val);
    
    // Base case: if the list contains only one node, return the root node.
    if(A == middleNode)
        return root;
    
    // Recursively build the left and right subtrees of the binary search tree
    // using the nodes to the left and right of the middle node.
    root->left = sortedListToBST(A);
    root->right = sortedListToBST(middleNode->next);
    
    // Return the root of the binary search tree.
    return root;
}

