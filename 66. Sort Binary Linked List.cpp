/*
Sort Binary Linked List
Programming
Linked Lists
Easy
71.9% Success

253

9

Bookmark
Asked In:
Problem Description

Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

You need to sort the linked list and return the new linked list.

NOTE:

Try to do it in constant space.


Problem Constraints
 1 <= N <= 105

 A.val = 0 or A.val = 1



Input Format
First and only argument is the head pointer of the linkedlist A.



Output Format
Return the head pointer of the new sorted linked list.



Example Input
Input 1:

 1 -> 0 -> 0 -> 1
Input 2:

 0 -> 0 -> 1 -> 1 -> 0


Example Output
Output 1:

 0 -> 0 -> 1 -> 1
Output 2:

 0 -> 0 -> 0 -> 1 -> 1


Example Explanation
Explanation 1:

 The sorted linked list looks like:
  0 -> 0 -> 1 -> 1
Explanation 2:

 The sorted linked list looks like:
  0 -> 0 -> 0 -> 1 -> 1
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    // If the given linked list is empty, return it as is
        if (!A) return A;
        
        // Initialize counters for values 0 and 1
        int cnt1 = 0, cnt2 = 0;
        ListNode* temp = A;
        
        // Count the number of nodes with value 0 and value 1
        while (temp) {
            if (temp->val)
                cnt2++;
            else
                cnt1++;
            temp = temp->next;
        }
        
        // Reset temp pointer to the head of the linked list
        temp = A;
        
        // Update the values of the nodes to 0 for the first cnt1 nodes
        int i = 0;
        while (i < cnt1) {
            temp->val = 0;
            temp = temp->next;
            i++;
        }
        
        // Update the values of the nodes to 1 for the remaining nodes (cnt2)
        i = 0;
        while (i < cnt2) {
            temp->val = 1;
            temp = temp->next;
            i++;
        }
        
        // Return the modified linked list
        return A;
}


/*
Intuition:
- We create two dummy nodes, one to represent the head of the group of nodes with value 1 (dummyOne), and the other to represent the head of the group of nodes with value 0 (dummyZero).
- We traverse the given linked list and segregate the nodes into two groups based on their values: nodes with value 1 are appended to the group represented by dummyOne, and nodes with value 0 are appended to the group represented by dummyZero.
- After traversing the entire list, we connect the end of the group of nodes with value 0 to the head of the group of nodes with value 1.
- Finally, we terminate the list by setting the next of the last node in the group of nodes with value 1 to nullptr.
- We return the head of the modified linked list represented by dummyZero->next.

Time Complexity: O(N)
- We traverse the entire linked list once, where N is the number of nodes in the linked list.

Space Complexity: O(1)
- We use only a constant amount of additional space, as we're not using any extra data structures proportional to the size of the input linked list.
*/

ListNode* Solution::solve(ListNode* A){
    // If the given linked list is empty, return it as is
    if (!A) return A;

    // Initialize dummy nodes for two groups
    ListNode* dummyOne = new ListNode(0);
    ListNode* dummyZero = new ListNode(1);

    // Pointers to track the end of each group
    ListNode* OneTail = dummyOne;
    ListNode* zeroTail = dummyZero;

    // Traverse the given linked list
    ListNode* curr = A;
    while (curr) {
        // If the current node's value is 1, append it to the group of nodes with value 1
        if (curr->val) {
            OneTail->next = curr;
            OneTail = OneTail->next;
        }
        // If the current node's value is 0, append it to the group of nodes with value 0
        else {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }
        // Move to the next node
        curr = curr->next;
    }

    // Connect the end of the group of nodes with value 0 to the head of the group of nodes with value 1
    zeroTail->next = dummyOne->next;
    // Set the next of the last node in the group of nodes with value 1 to nullptr
    OneTail->next = nullptr;

    // Return the head of the modified linked list
    return dummyZero->next;
}

