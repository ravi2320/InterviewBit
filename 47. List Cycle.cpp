/*
List Cycle
Programming
Linked Lists
Medium
56.8% Success

359

18

Bookmark
Asked In:
Problem Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example:

Input: 


              ______
             |     |
             \/    |
    1 -> 2 -> 3 -> 4


Return the node corresponding to node 3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(!A) return A;
    
    ListNode *fast = A;
    ListNode *slow = A;
    int flag = 0; 
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow){
            flag = 1;
            break;
        }
    }
    if(flag){
        fast = A;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    return NULL;
}
