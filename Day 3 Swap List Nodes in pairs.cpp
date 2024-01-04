/*
Swap List Nodes in pairs
Programming
Linked Lists
Easy
55.1% Success

295

11

Bookmark
Asked In:
Problem Description
 
 

Given a linked list A, swap every two adjacent nodes and return its head.

NOTE: Your algorithm should use only constant space. You may not modify the values in the list; only nodes themselves can be changed.



Problem Constraints
 1 <= |A| <= 106 



Input Format
 The first and the only argument of input contains a pointer to the head of the given linked list. 



Output Format
 Return a pointer to the head of the modified linked list. 



Example Input
 Input 1: 

 A = 1 -> 2 -> 3 -> 4
 Input 2: 

 A = 7 -> 2 -> 1


Example Output
 Output 1: 

 2 -> 1 -> 4 -> 3
 Output 2: 

 2 -> 7 -> 1


Example Explanation
Explanation 1:

 In the first example (1, 2) and (3, 4) are the adjacent nodes. Swapping them will result in 2 -> 1 -> 4 -> 3
Explanation 2:

 In the second example, 3rd element i.e. 1 does not have an adjacent node, so it won't be swapped. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
     ListNode* swap1(ListNode* next1, ListNode* next2) {
        next1->next = next2->next;
        next2->next = next1;
        return next2;
}
ListNode* Solution::swapPairs(ListNode *head) {
        ListNode* start = new ListNode(0); //make head no longer a special case
        start->next = head;

        ListNode *cur = start;
        while (cur->next != NULL && cur->next->next != NULL) {
            cur->next = swap1(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return start->next;
    }

ListNode* Solution::swapPairs(ListNode* A) 
{
    ListNode* head = A;
    for(ListNode* curr = head; curr != NULL && curr->next != NULL; curr = curr->next->next)
    {
        int temp = curr->val;
        curr->val = curr->next->val;
        curr->next->val = temp;
    }
    
    return head;
}
