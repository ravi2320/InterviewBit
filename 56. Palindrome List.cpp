/*
Palindrome List
Programming
Linked Lists
Medium
41.7% Success

301

10

Bookmark
Asked In:
Problem Description
 
 

Given a singly linked list A, determine if it's a palindrome. Return 1 or 0, denoting if it's a palindrome or not, respectively.



Problem Constraints
 1 <= |A| <= 105 



Input Format
The first and the only argument of input contains a pointer to the head of the given linked list. 



Output Format
 Return 0, if the linked list is not a palindrome. 

 Return 1, if the linked list is a palindrome. 



Example Input
 Input 1: 

A = [1, 2, 2, 1]
Input 2:

A = [1, 3, 2]


Example Output
 Output 1: 

 1 
 Output 2: 

 0 


Example Explanation
Explanation 1:

 The first linked list is a palindrome as [1, 2, 2, 1] is equal to its reversed form.
Explanation 2:

 The second linked list is not a palindrom as [1, 3, 2] is not equal to [2, 3, 1].


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    ListNode* prev = NULL;
    ListNode* slow = A;
    ListNode* fast = A;
    
    while(fast && fast->next){
        fast = fast->next->next;
        
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    if(fast != NULL)
        slow = slow->next;
        
    while(slow && prev){
        if(slow->val != prev->val)
            return 0;
        
        slow = slow->next;
        prev = prev->next;
    }
    
    return 1;
}
