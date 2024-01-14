/*
Rotate List
Programming
Linked Lists
Medium
32.1% Success

243

19

Bookmark
Asked In:
Problem Description
 
 

Given a list, rotate the list to the right by k places, where k is non-negative.


Problem Constraints
1 <= B <= 109


Input Format
The first argument is ListNode A, pointing to the head of the list.
The second argument is an integer B, representing the value of k.


Output Format
Return the rotated list.


Example Input
A = 1->2->3->4->5->NULL
B = 2


Example Output
4->5->1->2->3->NULL


Example Explanation
Given list: A = 1->2->3->4->5->NULL
Given B = 2;
After rotating A once, A = 5->1->2->3->4->NULL
After rotating A again, A = 4->5->1->2->3->NULL
Hence after rotating the given list A, for B = 2, return 4->5->1->2->3->NULL
*/

ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (A == NULL || A->next == NULL || B == 0) {
        return A;
    }

    // Count the number of nodes in the linked list
    ListNode* temp = A;
    int cnt = 1;  // Initialize with 1 to count the current node
    while (temp->next != NULL) {
        cnt++;
        temp = temp->next;
    }

    // Calculate the effective rotation
    B = B % cnt;
    if (B == 0) {
        return A;  // No rotation needed
    }

    // Find the new head and the new tail after rotation
    ListNode* newTail = A;
    for (int i = 1; i < cnt - B; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL;  // Set the new tail's next to NULL

    // Attach the original list to the end of the rotated list
    temp->next = A;

    return newHead;
}
